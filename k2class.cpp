#include "k2class.h"

k2class::k2class()
{
}

k2class::k2class(boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer)
{
    this->viewer = viewer;
}


//Function for registration step
void k2class::registration(std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> clouds)
{
    qDebug() << "Start registration step";

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr final_cloud (new pcl::PointCloud<pcl::PointXYZRGBA>());
    Point2Mesh p2m;
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr c1, c2;
    Eigen::Matrix4f transf_m = Eigen::Matrix4f::Identity ();
    Eigen::Matrix4f transf2p2;

    std::cout << "CLOUD_SIZE LOADED: " << clouds.size() << std::endl;

    for (int i = 1; i < clouds.size(); i++)
    {
        c1 = clouds[i-1];
        c2 = clouds[i];

        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr tmp (new pcl::PointCloud<pcl::PointXYZRGBA>());
        p2m.estimate_align(c1, c2, tmp, transf2p2, true);

        pcl::transformPointCloud (*tmp, *final_cloud, transf_m);
        transf_m = transf_m * transf2p2;

        qDebug() << "Finished Align";
    }

    //p2m.filtering (final_cloud);

    pcl::io::savePCDFile("pointcloud.pcd", *final_cloud, true);

    qDebug() << "Finished Registration";
}

void k2class::registrationSAC (std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> clouds)
{
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr c1 (new pcl::PointCloud<pcl::PointXYZRGBA>());
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr c2 (new pcl::PointCloud<pcl::PointXYZRGBA>());
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr _c1 (new pcl::PointCloud<pcl::PointXYZRGBA>());
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr _c2 (new pcl::PointCloud<pcl::PointXYZRGBA>());
    pcl::PointCloud<pcl::Normal>::Ptr normal_c1 (new pcl::PointCloud<pcl::Normal>);
    pcl::PointCloud<pcl::Normal>::Ptr normal_c2 (new pcl::PointCloud<pcl::Normal>);
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr previous (new pcl::PointCloud<pcl::PointXYZRGBA>());
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr final (new pcl::PointCloud<pcl::PointXYZRGBA>());
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr tmp (new pcl::PointCloud<pcl::PointXYZRGBA>());
    pcl::VoxelGrid<pcl::PointXYZRGBA> grid;
    Point2Mesh p2m;
    pcl::PointCloud<pcl::FPFHSignature33>::Ptr features_c1 = pcl::PointCloud<pcl::FPFHSignature33>::Ptr (new PointCloud<FPFHSignature33>);
    pcl::PointCloud<pcl::FPFHSignature33>::Ptr features_c2 = pcl::PointCloud<pcl::FPFHSignature33>::Ptr (new PointCloud<FPFHSignature33>);
    pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr kdtree = pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr (new search::KdTree<PointXYZRGBA>);
    pcl::FPFHEstimation<pcl::PointXYZRGBA, pcl::Normal, pcl::FPFHSignature33> FPFH_est;
    pcl::SampleConsensusInitialAlignment<pcl::PointXYZRGBA, pcl::PointXYZRGBA, pcl::FPFHSignature33> SACIA;

    grid.setLeafSize (0.01f, 0.01f, 0.01f);
    previous = clouds[0];
    for (size_t i = 1; i < clouds.size(); i++)
    {
        c1 = previous;
        c2 = clouds[i];

        //Remove NaN and downsampling
        std::vector<int> indices;
        pcl::removeNaNFromPointCloud (*c1,*c1,indices);
        pcl::removeNaNFromPointCloud (*c2,*c2,indices);
        grid.setInputCloud (c1);
        grid.filter (*_c1);
        grid.setInputCloud (c2);
        grid.filter (*_c2);

        p2m.calc_normal(_c1, normal_c1);
        p2m.calc_normal(_c2, normal_c2);


        //Compute FPFH features for _c1 cloud
        FPFH_est.setInputCloud(_c1);
        FPFH_est.setInputNormals(normal_c1);
        FPFH_est.setSearchMethod(kdtree);
        FPFH_est.setRadiusSearch(0.01);
        FPFH_est.compute(*features_c1);

        //Compute FPFH features for _c2 cloud
        FPFH_est.setInputCloud(_c2);
        FPFH_est.setInputNormals(normal_c2);
        FPFH_est.setSearchMethod(kdtree);
        FPFH_est.setRadiusSearch(0.01);
        FPFH_est.compute(*features_c2);

        //SAC-IA alignment
        SACIA.setInputCloud(_c2);
        SACIA.setSourceFeatures(features_c2);
        SACIA.setInputTarget(_c1);
        SACIA.setTargetFeatures(features_c1);
        SACIA.setMaximumIterations(300);
        SACIA.align(*tmp);

        Eigen::Matrix4f f_transf = SACIA.getFinalTransformation();
        pcl::transformPointCloud(*c2, *c2, f_transf);
        *final = *c1;
        *final += *c2;

        previous = final;
        std::cout << "DONE." << std::endl;
    }

    pcl::io::savePCDFile("pointcloud_SAC.pcd", *final, true);
}










































