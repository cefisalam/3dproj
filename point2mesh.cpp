#include "point2mesh.h"

Point2Mesh::Point2Mesh(QObject *parent) : QObject(parent)
{

}

void Point2Mesh::calc_normals(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud,
                              pcl::PointCloud<pcl::PointNormal>::Ptr pc_normals)
{
    pcl::NormalEstimation<pcl::PointXYZRGBA, pcl::PointNormal> normal_est;
    pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr kdtree (new pcl::search::KdTree<pcl::PointXYZRGBA> ());
    normal_est.setSearchMethod (kdtree);
    normal_est.setKSearch (30);

    normal_est.setInputCloud(cloud);
    normal_est.compute (*pc_normals);
    pcl::copyPointCloud (*cloud, *pc_normals);
}

void Point2Mesh::estimate_align (pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud1,
                                 pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr cloud2,
                                 pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud_final,
                                 Eigen::Matrix4f &transf_m,
                                 bool flag)

{

    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr c1 (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr c2 (new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::PointCloud<pcl::PointNormal>::Ptr normal_c1 (new pcl::PointCloud<pcl::PointNormal>);
    pcl::PointCloud<pcl::PointNormal>::Ptr normal_c2 (new pcl::PointCloud<pcl::PointNormal>);
    pcl::VoxelGrid<pcl::PointXYZRGBA> grid;
    PointA new_point;
    float init_values [4] = {1.0, 1.0, 1.0, 1.0};

    if (flag == true)
    {
        grid.setLeafSize (0.05, 0.05, 0.05);
        grid.setInputCloud (cloud1);
        grid.filter (*c1);

        grid.setInputCloud (cloud2);
        grid.filter (*c2);
    }

    else
    {
        c1 = cloud1->makeShared();
        c2 = cloud2->makeShared();
    }

    calc_normals(c1, normal_c1);
    calc_normals(c2, normal_c2);

    new_point.setRescaleValues (init_values);

    pcl::IterativeClosestPointNonLinear<pcl::PointNormal, pcl::PointNormal> icp;
    icp.setTransformationEpsilon (1e-6);
    icp.setMaxCorrespondenceDistance (0.05);
    icp.setPointRepresentation (boost::make_shared<const PointA> (new_point));

    icp.setInputSource (normal_c1);
    icp.setInputTarget (normal_c2);

    Eigen::Matrix4f m_identity = Eigen::Matrix4f::Identity();
    Eigen::Matrix4f previous, trgt;
    pcl::PointCloud<pcl::PointNormal>::Ptr icp_res = normal_c1;
    icp.setMaximumIterations(2);

    for (int i = 0; i < 30; i++)
    {
        normal_c1 = icp_res;

        icp.setInputSource(normal_c1);
        icp.align(*icp_res);

        m_identity = icp.getFinalTransformation() * m_identity;

        if (fabs ((icp.getLastIncrementalTransformation () -
                   previous).sum ()) < icp.getTransformationEpsilon ())
        {
            icp.setMaxCorrespondenceDistance (icp.getMaxCorrespondenceDistance () - 0.001);
        }

        previous = icp.getLastIncrementalTransformation();
    }

    trgt = m_identity.inverse();

    pcl::transformPointCloud(*cloud2, *cloud_final, trgt);
    //std::cout << "Here" << std::endl;

    *cloud_final += *cloud1;
    transf_m = trgt;
}
