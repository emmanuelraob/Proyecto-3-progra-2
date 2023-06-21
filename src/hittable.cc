#include <hittable.hh>
#include <ray.hh>
#include <rtweekend.hh>
#include <vec3.hh>

void hit_record::set_face_normal(const ray &r, const vec3 &outward_normal) {
  front_face = dot(r.direction(), outward_normal) < 0;
  normal = front_face ? outward_normal : -outward_normal;
}