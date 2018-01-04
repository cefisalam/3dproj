#include "point2mesh.h"

Point2Mesh::Point2Mesh(QObject *parent) : QObject(parent)
{
}

void Point2Mesh::calc_normals(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,
                              pcl::PointCloud<pcl::PointNormal>::Ptr pc_normals)
{
    pcl::NormalEstimation<pcl::PointXYZ, pcl::PointNormal> normal_est;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree (new pcl::search::KdTree<pcl::PointXYZ> ());
    normal_est.setSearchMethod (kdtree);
    normal_est.setKSearch (30);

    normal_est.setInputCloud(cloud);
    normal_est.compute (*pc_normals);
    pcl::copyPointCloud (*cloud, *pc_normals);
}

void Point2Mesh::point2mesh (pcl::PCLPointCloud2 cloud)
{
    pcl::PointCloud<pcl::Normal>::Ptr normal (new pcl::PointCloud<pcl::Normal>);
    pcl::PointCloud<pcl::PointNormal>::Ptr normal_pc (new pcl::PointCloud<pcl::PointNormal>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_pcl (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PolygonMesh triangles;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr kdtree (new pcl::search::KdTree<pcl::PointXYZ>);
    pcl::search::KdTree<pcl::PointNormal>::Ptr kdtreeN (new pcl::search::KdTree<pcl::PointNormal>);
    pcl::GreedyProjectionTriangulation<pcl::PointNormal> greedy;

    pcl::fromPCLPointCloud2 (cloud, *cloud_pcl);

    //Normal estimation
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_est;
    kdtree->setInputCloud(cloud_pcl);
    normal_est.setInputCloud(cloud_pcl);
    normal_est.setSearchMethod(kdtree);
    normal_est.setKSearch(10);
    normal_est.compute(*normal);

    pcl::concatenateFields(*cloud_pcl, *normal, *normal_pc);
    kdtreeN->setInputCloud(normal_pc);

    greedy.setSearchRadius (0.025);
    greedy.setMu (2.5);
    greedy.setMaximumNearestNeighbors (100);
    greedy.setMaximumSurfaceAngle(M_PI/4);
    greedy.setMinimumAngle(M_PI/18);
    greedy.setMaximumAngle(2*M_PI/3);
    greedy.setNormalConsistency(false);
    greedy.setInputCloud (normal_pc);
    greedy.setSearchMethod (kdtreeN);
    greedy.reconstruct (triangles);

    std::vector<int> parts = greedy.getPartIDs();
    std::vector<int> states = greedy.getPointStates();

    std::cout << "PARTS: " << parts.size() << std::endl;
    std::cout << "STATES: " << states.size() << std::endl;

    std::string str = "teste2.stl";
    pcl::io::savePolygonFileSTL(str, triangles, true);

    std::cout << "FINSHED TRIANGLE" << std::endl;
}

void Point2Mesh::estimate_align (pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud1,
                                 pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud2,
                                 pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_final,
                                 Eigen::Matrix4f &transf_m,
                                 bool flag)

{

    pcl::PointCloud<pcl::PointXYZ>::Ptr c1 (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr c2 (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointNormal>::Ptr normal_c1 (new pcl::PointCloud<pcl::PointNormal>);
    pcl::PointCloud<pcl::PointNormal>::Ptr normal_c2 (new pcl::PointCloud<pcl::PointNormal>);
    pcl::VoxelGrid<pcl::PointXYZ> grid;
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
    icp.setMaxCorrespondenceDistance (0.2);
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
