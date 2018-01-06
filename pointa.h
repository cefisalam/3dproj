#ifndef POINTA_H
#define POINTA_H

#include <boost/make_shared.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/point_representation.h>

/*Class create to manage another kind of point, for registragion step.
This point preserves the normal values onto 3 axis + curvarure value
of each point*/
class PointA : public pcl::PointRepresentation <pcl::PointNormal>
{
  using pcl::PointRepresentation<pcl::PointNormal>::nr_dimensions_;

public:
  PointA (){nr_dimensions_ = 4;}
  virtual void copyToFloatArray (const pcl::PointNormal &p_normal, float *final) const
  {
    // < x, y, z, curvature >
    final[0] = p_normal.x;
    final[1] = p_normal.y;
    final[2] = p_normal.z;
    final[3] = p_normal.curvature;
  }
};


#endif // POINTA_H
