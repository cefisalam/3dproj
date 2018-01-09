#ifndef K2CLASS_H
#define K2CLASS_H

//Internal
#include "point2mesh.h"
#include "kinect2_grabber.h"

//QT
#include <QObject>
#include <vector>

//PCL
#include <pcl/common/angles.h>
#include <pcl/io/openni2_grabber.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/boost.h>
#include <pcl/visualization/image_viewer.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/console/time.h>
#include <pcl/io/openni2/openni.h>
#include <boost/chrono.hpp>
#include <pcl/filters/passthrough.h>
#include <pcl/io/ply_io.h>
#include <pcl/console/print.h>
#include <pcl/console/parse.h>
#include <pcl/features/fpfh.h>
#include <Eigen/Core>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/registration/ia_ransac.h>

using namespace pcl;

class k2class
{

public:
    k2class();
    k2class(boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer);
    void registration(std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> clouds);
    void registrationSAC (std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> clouds);

private:
     boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;

};

#endif // K2CLASS_H
