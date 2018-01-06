#include "k1class.h"

k1class::k1class(QObject *parent) : QObject(parent),
    clouds (0),
    time (0),
    min (0),
    max (0),
    final_cloud (new pcl::PointCloud<pcl::PointXYZ>),
    filter_cloud (new pcl::PointCloud<pcl::PointXYZ>),
    flag_start(false)
{
}

//Function for registration step
void k1class::registration(std::vector<pcl::PointCloud<pcl::PointXYZ>::ConstPtr> clouds)
{

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

    p2m.filtering (final_cloud);

    pcl::io::savePCDFile("pointcloud.pcd", *final_cloud, true);
    pcl::PCLPointCloud2 cloud;
    pcl::io::loadPCDFile("pointcloud.pcd", cloud);

    //p2m.point2mesh(cloud);

    //    std::stringstream ss1;
    //    ss1 << "teste1.ply";
    //    pcl::PLYWriter writer;
    //    writer.write (ss1.str(), cloud , Eigen::Vector4f::Zero (),
    //                  Eigen::Quaternionf::Identity (), true, true);

    //    pcl::PolygonMesh mesh;
    //    pcl::io::loadPLYFile(ss1.str(), mesh);

    std::cout << "FINISHED" << std::endl;
}
