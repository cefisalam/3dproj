#ifndef K1CLASS_H
#define K1CLASS_H

#include "point2mesh.h"

#include <QObject>
#include <QTime>
#include <vector>

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
    pcl::visualization::CloudViewer viewer;
    std::vector<pcl::PointCloud<pcl::PointXYZ>::ConstPtr> clouds;
    pcl::PointCloud<pcl::PointXYZ>::Ptr final_cloud;
    Point2Mesh p2m;

signals:

public slots:
    void cloud_cb_func (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud);
    void init();
    void registration(std::vector<pcl::PointCloud<pcl::PointXYZ>::ConstPtr> clouds);
};

#endif // K1CLASS_H
