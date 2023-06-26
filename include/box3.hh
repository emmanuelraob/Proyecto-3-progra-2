#ifndef BOX3_HH
#define BOX3_HH

#include <vec3.hh>
#include <hittable.hh>
#include <vector>

using namespace std;

class Box3{
    public:
        Box3(){}
        Box3(point3 bound1, point3 bound2){
            this->bounds[0] = bound1;
            this->bounds[1] = bound2;
        }
        unique_ptr<Box3> half_left;
        unique_ptr<Box3> half_right;

        point3 bounds[2];

        vector<hittable*> objects;

        bool is_hittable_inside(hittable* object);
        bool does_box_contain_a_hittable();
        void add_hittable(Box3& box, hittable* object, int dimension);
        void build_box(Box3& first_box, vector<hittable*> objects);
        bool does_ray_hit(const ray& r);

};

#endif