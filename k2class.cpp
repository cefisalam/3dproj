#include "k2class.h"

k2class::k2class()
{
}

k2class::k2class(boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer)
{
    this->viewer = viewer;
}


//Function for registration step
void k2class::registration(std::vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> clouds)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr final_cloud (new pcl::PointCloud<pcl::PointXYZ>());
    Point2Mesh p2m;
    pcl::PointCloud<pcl::PointXYZ>::Ptr c1, c2;
    Eigen::Matrix4f transf_m = Eigen::Matrix4f::Identity (), transf2p2;

    for (int i = 1; i < clouds.size(); i++)
    {
        c1 = clouds.at(i-1);
        c2 = clouds.at(i);

        std::vector<int> index;
        pcl::removeNaNFromPointCloud(*c1,*c1, index);

        index.clear();
        pcl::removeNaNFromPointCloud(*c2,*c2, index);

        pcl::PointCloud<pcl::PointXYZ>::Ptr tmp (new pcl::PointCloud<pcl::PointXYZ>());

        p2m.estimate_align(c1, c2, tmp, transf2p2, true);

        pcl::transformPointCloud (*tmp, *final_cloud, transf_m);
        transf_m = transf_m * transf2p2;
    }

    qDebug() << "Finished the estimate_align";

    p2m.filtering (final_cloud);

    pcl::io::savePCDFile("pointcloud.pcd", *final_cloud, true);

    qDebug() << "Finished Registration";
}
