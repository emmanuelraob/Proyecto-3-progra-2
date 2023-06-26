#include <hittable_list.hh>
#include <hittable.hh>
#include <memory>
#include <vector>
#include <box3.hh>


using std::shared_ptr;
using std::make_shared;

hittable_list::hittable_list() {}

hittable_list::hittable_list(shared_ptr<hittable> object) {
    add(object);
}

void hittable_list::clear() {
    objects.clear();
}

void hittable_list::add(shared_ptr<hittable> object) {
    objects.push_back(object);
}

void does_ray_hit_sphere(Box3& box, const ray& r, double t_min, double t_max, hit_record& rec, bool* sphere_hit){

    if (box.does_ray_hit(r)){
        if (box.objects.size() > 0){
            hit_record temp_rec;
            auto closest_so_far = t_max;
            if (sphere_hit){
                closest_so_far = rec.t;
            }

            for (const auto& object : box.objects) {
                if (object->hit(r, t_min, closest_so_far, temp_rec)) {
                    *sphere_hit = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }
        }

        if (box.half_left != nullptr){
            does_ray_hit_sphere(*box.half_left, r, t_min, t_max, rec, sphere_hit);
        }
        if (box.half_right != nullptr){
            does_ray_hit_sphere(*box.half_right, r, t_min, t_max, rec, sphere_hit);
        }
    }
}

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) {

    bool ray_hit_sphere = false;
    does_ray_hit_sphere(first_box, r, t_min, t_max, rec, &ray_hit_sphere);
    return ray_hit_sphere;

}

shared_ptr<hittable> hittable_list::biggerSphere(int dimension){
    shared_ptr<hittable> biggerS = objects[0];
    for (int i = 1; i < objects.size(); i++){
        if (objects[i]->get_center()[dimension] > biggerS->get_center()[dimension]){
            biggerS = objects[i];
       }
    }
    return biggerS;
}

shared_ptr<hittable> hittable_list::smallerSphere(int dimension){
    shared_ptr<hittable> smallerS = objects[0];
    for (int i = 1; i < objects.size(); i++){
        if (objects[i]->get_center()[dimension] < smallerS->get_center()[dimension]){
            smallerS = objects[i];
       }
    }
    return smallerS;
}

point3 hittable_list::get_center() const{return point3(0,0,0);}

void hittable_list::set_closest_point(point3 point){}

double hittable_list::get_distance_from_center(){return 0;}