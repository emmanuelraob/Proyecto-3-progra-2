#ifndef RAY_HH
#define RAY_HH

#include <vec3.hh>

class ray {
    public:
        ray() {}
        ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {
            sign[0] = direction.x() < 0;
            sign[0] = direction.y() < 0;
            sign[0] = direction.z() < 0;
            invdir = 1.0/direction;
        }

        point3 origin() const  { return orig; }
        vec3 direction() const { return dir; }

        point3 at(double t) const {
            return orig + t*dir;
        }

    public:
        point3 orig;
        vec3 dir;
        bool sign[3];
        vec3 invdir;
};

bool compare_rays(ray ray1, ray ray2);

#endif