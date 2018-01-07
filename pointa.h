#ifndef POINTA_H
#define POINTA_H

#include <boost/make_shared.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/point_representation.h>

//Class for creation of a new PointType, to save normal axis (x,y,z) + curvature normal value
class PointA : public pcl::PointRepresentation <pcl::PointNormal>
{
  using pcl::PointRepresentation<pcl::PointNormal>::nr_dimensions_;

public:
  PointA (){nr_dimensions_ = 4;}
  virtual void copyToFloatArray (const pcl::PointNormal &p_normal, float *final) const
  {
    final[0] = p_normal.x;
    final[1] = p_normal.y;
    final[2] = p_normal.z;
    final[3] = p_normal.curvature;
  }
};


#endif // POINTA_H
