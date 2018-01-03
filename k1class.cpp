#include "k1class.h"

k1class::k1class(QObject *parent) : QObject(parent),
    viewer ("PCL OpenNI Viewer"),
    clouds (0),
    p2m (nullptr)
{
}

void k1class::cloud_cb_func(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr& cloud)
{
    if (!viewer.wasStopped())
        viewer.showCloud (cloud);

    clouds.push_back(cloud);
    //pcl::io::savePLYFile(file_path, *cloud, true);
}

void k1class::init ()
{
    int time = 0;
    pcl::Grabber *grabber = new pcl::io::OpenNI2Grabber();

    boost::function<void (const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)> func_cb =
            boost::bind (&k1class::cloud_cb_func, this, _1);

    grabber->registerCallback (func_cb);
    grabber->start();

    while (time < 2)
    {
        boost::this_thread::sleep (boost::posix_time::seconds (1));
        time++;
    }

    grabber->stop ();
}

void k1class::registration(std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr> clouds)
{

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr final_cloud (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr c1, c2;
    Eigen::Matrix4f transf_m = Eigen::Matrix4f::Identity (), transf2p2;

    for (int i = 1; i < clouds.size(); i++)
    {
        c1 = clouds.at(i-1);
        c2 = clouds.at(i);

        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr tmp (new pcl::PointCloud<pcl::PointXYZRGBA>);

        p2m.estimate_align(c1, c2, tmp, transf2p2, true);

        pcl::transformPointCloud (*tmp, *final_cloud, transf_m);
        transf_m = transf_m * transf2p2;

    }
    std::stringstream ss;
    ss << "teste1.ply";
    pcl::io::savePCDFile(ss.str(), *final_cloud, true);

    pcl::PCLPointCloud2 cloud;
    pcl::io::loadPCDFile(ss.str(), cloud);

    std::stringstream ss1;
    ss1 << "teste1.pcd";
    pcl::PLYWriter writer;
    writer.write (ss1.str(), cloud , Eigen::Vector4f::Zero (),
                  Eigen::Quaternionf::Identity (), true, true);

    std::cout << "FINISHED" << std::endl;
}
