#ifndef POINT2MESH_H
#define POINT2MESH_H

//Qt
#include <QObject>
#include <QDebug>

//PCL
#include <boost/make_shared.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/point_representation.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/ascii_io.h>
#include <pcl/io/vtk_io.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/io/openni2_grabber.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/parse.h>
#include <pcl/common/time.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/filter.h>
#include <pcl/filters/median_filter.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/registration/icp.h>
#include <pcl/registration/icp_nl.h>
#include <pcl/registration/transforms.h>
#include <pcl/registration/correspondence_estimation.h>
#include <pcl/registration/correspondence_estimation_normal_shooting.h>
#include <pcl/registration/correspondence_estimation_backprojection.h>
#include <pcl/registration/correspondence_rejection_median_distance.h>
#include <pcl/registration/correspondence_rejection_surface_normal.h>
#include <pcl/registration/transformation_estimation_point_to_plane_lls.h>
#include <pcl/registration/default_convergence_criteria.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/gp3.h>
#include <pcl/surface/mls.h>
#include <pcl/surface/poisson.h>


class Point2Mesh : public QObject
{
    Q_OBJECT
public:
    explicit Point2Mesh(QObject *parent = nullptr);

signals:

public slots:
    void calc_normals(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud,
                      pcl::PointCloud<pcl::PointNormal>::Ptr pc_normals);
    void estimate_align (const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud1,
                         const pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud2,
                         pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_final,
                         Eigen::Matrix4f &transf_m,
                         bool flag);

    void point2mesh (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_pcl, int type, int depth);
    void filtering (pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);
};

#endif // POINT2MESH_H
