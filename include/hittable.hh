#ifndef HITTABLE_HH
#define HITTABLE_HH

#include <ray.hh>
#include <rtweekend.hh>
#include <vec3.hh>

class material;

struct hit_record {
  point3 p;
  vec3 normal;
  shared_ptr<material> mat_ptr;
  double t;
  bool front_face;

  void set_face_normal(const ray &r, const vec3 &outward_normal);
};

class hittable {
public:
  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &rec) = 0;

  virtual point3 get_center() const = 0;

  virtual void set_closest_point(point3 point) = 0;

  virtual double get_distance_from_center() = 0;
};

#endif