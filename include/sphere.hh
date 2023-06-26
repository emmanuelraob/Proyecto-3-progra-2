#ifndef SPHERE_HH
#define SPHERE_HH

#include <hittable.hh>
#include <vec3.hh>

class sphere : public hittable {
public:
  sphere() {}
  sphere(point3 cen, double r, shared_ptr<material> m);

  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &rec) override;
              
  virtual point3 get_center() const override;

  virtual void set_closest_point(point3 point) override;
  
  double get_distance_from_center();
public:
  point3 center;
  double radius;
  shared_ptr<material> mat_ptr;
  point3 closest_point_camera;
};

#endif