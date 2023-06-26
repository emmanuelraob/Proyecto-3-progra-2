#include <box3.hh>
#include <cmath>

bool Box3::is_hittable_inside(hittable* object){
    point3 oc = object->get_center();
    for (int i = 0; i < 3; i++){
        if (!(oc[i] <= bounds[0][i] && oc[i] >= bounds[1][i]) && !(oc[i] >= bounds[0][i] && oc[i] <= bounds[1][i])){
            return false;
        }
    }
    return true;
}

void Box3::build_all_box_levels(Box3& box, int current_lvl, int final_lvl, int dimension){
    if (current_lvl < final_lvl){
        point3 upper_bound = box.bounds[1];
        point3 lower_bound = box.bounds[0];
        point3 half_left_upper_bound = upper_bound;
        half_left_upper_bound[dimension] /= 2.0;
        point3 half_right_lower_bound = half_left_upper_bound;
        point3 half_right_upper_bound = lower_bound;
        half_right_upper_bound[dimension] = upper_bound[dimension];

        box.half_left = make_unique<Box3>(lower_bound, half_left_upper_bound);
        box.half_right = make_unique<Box3>(half_right_lower_bound, half_right_upper_bound);
        build_all_box_levels(*box.half_left, current_lvl+1, final_lvl, (dimension + 1) % 3);
        build_all_box_levels(*box.half_right, current_lvl+1, final_lvl, (dimension + 1) % 3);
    }
}

void Box3::add_hittable(Box3& box, hittable* object, int dimension){
    

    if (box.half_left != nullptr && box.half_left->is_hittable_inside(object)){
        add_hittable(*box.half_left, object, (dimension + 1) % 3);
    }
    if (box.half_right != nullptr && box.half_right->is_hittable_inside(object)){
        add_hittable(*box.half_right, object, (dimension + 1) % 3);
    }

    if (box.half_left == nullptr && box.half_right == nullptr){
        box.objects.push_back(object);
    }
}

void Box3::build_box(Box3& first_box, vector<hittable*> objects){
    
    build_all_box_levels(first_box, 0, (int)log2(objects.size()), 0);
    for (int i = 0; i < objects.size(); i++){
        add_hittable(first_box, objects[i], 0);
    }
}

bool Box3::does_ray_hit(const ray& r){
    float tmin, tmax, tymin, tymax, tzmin, tzmax;
    
    tmin = (bounds[r.sign[0]].x() - r.orig.x()) * r.invdir.x();
    tmax = (bounds[1-r.sign[0]].x() - r.orig.x()) * r.invdir.x();
    tymin = (bounds[r.sign[1]].y() - r.orig.y()) * r.invdir.y();
    tymax = (bounds[1-r.sign[1]].y() - r.orig.y()) * r.invdir.y();
    
    if ((tmin > tymax) || (tymin > tmax))
        return false;

    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;
    
    tzmin = (bounds[r.sign[2]].z() - r.orig.z()) * r.invdir.z();
    tzmax = (bounds[1-r.sign[2]].z() - r.orig.z()) * r.invdir.z();
    
    if ((tmin > tzmax) || (tzmin > tmax))
        return false;

    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;

    return true;
}

bool does_ray_hit_sphere(Box3& box, ray& r, double t_min, double t_max, hit_record& rec){
    if (box.does_ray_hit(r)){
        if (box.half_left != nullptr){
            does_ray_hit_sphere(*box.half_left, r, t_min, t_max, rec);
        }
        if (box.half_right != nullptr){
            does_ray_hit_sphere(*box.half_right, r, t_min, t_max, rec);
        }
    }

    if (box.objects.size() > 0){
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = t_max;

        for (const auto& object : box.objects) {
            if (object->hit(r, t_min, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
}