#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "vec3.h"

class material;

struct hit_record
{
    vec3 p;
    vec3 normal;
    material *mat_ptr;
    float t;
};

class hittable  {
    public:
        __device__ virtual bool hit(const ray& r, float t_min, float t_max, 
                                    hit_record& rec) const = 0;
};

#endif
