#include "k1class.h"

k1class::k1class(QObject *parent) : QObject(parent),
    viewer ("Viewer 1"),
    clouds (0),
    p2m (nullptr),
    final_cloud (new pcl::PointCloud<pcl::PointXYZ>)
{
}

void k1class::cloud_cb_func(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud)
{
    if (!viewer.wasStopped())
        viewer.showCloud (cloud);

    pcl::PointCloud<pcl::PointXYZ>::Ptr filter_cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PassThrough<pcl::PointXYZ> filter;

    filter.setInputCloud(cloud);
    filter.setFilterFieldName("z");
    filter.setFilterLimits(0.0, 1.0);

    filter.filter(*filter_cloud);
    //pcl::io::savePLYFile("t.ply", *filter_cloud, true);
    clouds.push_back(filter_cloud);
}

void k1class::init ()
{

    pcl::Grabber *grabber = new pcl::io::OpenNI2Grabber();

    boost::function<void (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> func_cb =
            boost::bind (&k1class::cloud_cb_func, this, _1);

    grabber->registerCallback (func_cb);

    grabber->start();

    //QTime initial_time = QTime::currentTime().addSecs(10);
    //QTime final_time;
    //std::cout << "INITIAL: " << initial_time.second() << std::endl;
    while (!viewer.wasStopped())
    {
        boost::this_thread::sleep (boost::posix_time::seconds (1));
        //final_time = QTime::currentTime();
        //std::cout << "FINAL: " << final_time.second() << std::endl;
    }

    grabber->stop ();
}

void k1class::registration(std::vector<pcl::PointCloud<pcl::PointXYZ>::ConstPtr> clouds)
{

    //pcl::PointCloud<pcl::PointXYZ>::Ptr final_cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::ConstPtr c1, c2;
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

    pcl::io::savePCDFile("pointcloud.pcd", *final_cloud, true);
    pcl::PCLPointCloud2 cloud;
    pcl::io::loadPCDFile("pointcloud.pcd", cloud);

    p2m.point2mesh(cloud);

    //    std::stringstream ss1;
    //    ss1 << "teste1.ply";
    //    pcl::PLYWriter writer;
    //    writer.write (ss1.str(), cloud , Eigen::Vector4f::Zero (),
    //                  Eigen::Quaternionf::Identity (), true, true);

    //    pcl::PolygonMesh mesh;
    //    pcl::io::loadPLYFile(ss1.str(), mesh);

    std::cout << "FINISHED" << std::endl;
}
