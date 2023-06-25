#include <hittable_list.hh>
#include <hittable.hh>
#include <memory>
#include <vector>

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

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    for (const auto& object : objects) {
        if (object->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

hittable* hittable_list::biggerSphere(vector<hittable*> esferas, int dimension){
    hittable* biggerS = esferas[0];
    for (int i = 1; i < esferas.size(); i++){
        if (esferas[i]->get_center()[dimension] > biggerS->get_center()[dimension]){
            biggerS = esferas[i];
       }
    }
    return biggerS;
}

hittable* hittable_list::smallerSphere(vector<hittable*> esferas, int dimension){
    hittable* smallerS = esferas[0];
    for (int i = 1; i < esferas.size(); i++){
        if (esferas[i]->get_center()[dimension] < smallerS->get_center()[dimension]){
            smallerS = esferas[i];
        }
    }
    return smallerS;
}

point3 hittable_list::get_center() const{return point3(0,0,0);}

void hittable_list::set_closest_point(point3 point){}