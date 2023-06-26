#ifndef HITTABLE_LIST_HH
#define HITTABLE_LIST_HH

#include <hittable.hh>
#include <sphere.hh>
#include <memory>
#include <vector>
#include <box3.hh>

using std::vector;
using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
    public:
        hittable_list();
        hittable_list(shared_ptr<hittable> object);

        void clear();
        void add(shared_ptr<hittable> object);

        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) override;

        point3 get_center() const;

        void set_closest_point(point3 point);

        double get_distance_from_center();
        
        shared_ptr<hittable> biggerSphere(int dimension);

        shared_ptr<hittable> smallerSphere(int dimension);

    public:
        std::vector<shared_ptr<hittable>> objects;
        Box3 first_box;
};

#endif