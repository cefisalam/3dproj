#ifndef K1CLASS_H
#define K1CLASS_H

//Internal
#include "point2mesh.h"

//QT
#include <QObject>
#include <QTime>
#include <vector>
#include <QDebug>

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


class k1class : public QObject
{
    Q_OBJECT

public:
    explicit k1class(QObject *parent = nullptr);
    std::vector<pcl::PointCloud<pcl::PointXYZ>::ConstPtr> clouds;
    //std::vector<std::string> path_vec;
    pcl::PointCloud<pcl::PointXYZ>::Ptr final_cloud;
    pcl::PointCloud<pcl::PointXYZ>::Ptr filter_cloud;
    Point2Mesh p2m;
    int time, min, max;
    bool flag_start;

public slots:
    void registration(std::vector<pcl::PointCloud<pcl::PointXYZ>::ConstPtr> clouds);

protected:
    pcl::Grabber *grabber_var;
    pcl::PointCloud<pcl::PointXYZ>::ConstPtr cloud_final;

private:
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
};

#endif // K1CLASS_H
