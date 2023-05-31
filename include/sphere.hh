#ifndef SPHERE_HH
#define SPHERE_HH

#include <hittable.hh>
#include <vec3.hh>
#include <immintrin.h>

class sphere : public hittable {
public:
  sphere() {}
  sphere(point3 cen, double r, shared_ptr<material> m);

  virtual bool hit(const ray &r, double t_min, double t_max,
                   hit_record &rec) const override;

public:
  point3 center;
  double radius;
  shared_ptr<material> mat_ptr;
};

#endif