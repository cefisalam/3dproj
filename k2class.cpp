#include "k2class.h"

//std::vector<pcl::PointCloud<pcl::PointXYZ>::ConstPtr> clouds;

k2class::k2class(QObject *parent) : QObject(parent),
    clouds (0),
    p2m (nullptr),
    time(0),
    final_cloud (new pcl::PointCloud<pcl::PointXYZ>)
{
}

void k2class::registration(std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> clouds)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr c1, c2;
    Eigen::Matrix4f transf_m = Eigen::Matrix4f::Identity (), transf2p2;

    for (int i = 1; i < clouds.size(); i++)
    {
        c1 = clouds.at(i-1);
        c2 = clouds.at(i);

        pcl::PointCloud<pcl::PointXYZ>::Ptr tmp (new pcl::PointCloud<pcl::PointXYZ>);

        p2m.estimate_align(c1, c2, tmp, transf2p2, true);

        pcl::transformPointCloud (*tmp, *final_cloud, transf_m);
        transf_m = transf_m * transf2p2;
    }

    pcl::io::savePCDFile("point.pcd", *final_cloud, true);
    pcl::io::savePLYFile("point.ply", *final_cloud, true);

    //    pcl::PCLPointCloud2 cloud;
    //    pcl::io::loadPCDFile(ss.str(), cloud);

    //    p2m.point2mesh(cloud);

    //    std::stringstream ss1;
    //    ss1 << "teste1.ply";
    //    pcl::PLYWriter writer;
    //    writer.write (ss1.str(), cloud , Eigen::Vector4f::Zero (),
    //                  Eigen::Quaternionf::Identity (), true, true);

    //    pcl::PolygonMesh mesh;
    //    pcl::io::loadPLYFile(ss1.str(), mesh);

    std::cout << "FINISHED" << std::endl;
}

void k2class::init(std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> clouds)
{
    clouds.clear();
    boost::mutex mt;
    pcl::PointCloud<pcl::PointXYZ>::ConstPtr local_cloud (new pcl::PointCloud<pcl::PointXYZ>());
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("Viewer 2"));

    boost::function<void( const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& )> func_cb =
            [&local_cloud, &mt]( const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& ptr)
    {
        boost::mutex::scoped_lock lock (mt);
        local_cloud = ptr->makeShared();
    };

    boost::shared_ptr<pcl::Grabber> grabber = boost::make_shared<pcl::Kinect2Grabber>();
    grabber->registerCallback(func_cb);
    grabber->start();
    viewer->setCameraPosition( 0.0, 0.0, -2.5, 0.0, 0.0, 0.0 );
    int time = 0;
    while (!viewer->wasStopped())
    {
        boost::mutex::scoped_try_lock lock (mt);
        if(lock.owns_lock() && local_cloud)
        {
            if (!viewer->updatePointCloud(local_cloud, "cloud"))
            {
                viewer->addPointCloud(local_cloud, "cloud");
                clouds.push_back(local_cloud->makeShared());
            }
//          std::cout << "time: " << time << std::endl;
//          time++;
        }
    }

    grabber->stop();

}
