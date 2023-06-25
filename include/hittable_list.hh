#ifndef HITTABLE_LIST_HH
#define HITTABLE_LIST_HH

#include <hittable.hh>
#include <sphere.hh>
#include <memory>
#include <vector>

using std::vector;
using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
    public:
        hittable_list();
        hittable_list(shared_ptr<hittable> object);

        void clear();
        void add(shared_ptr<hittable> object);

        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

        virtual hittable* biggerSphere(vector<hittable*> esferas, int dimension) = 0;

        virtual hittable* smallerSphere(vector<hittable*> esferas, int dimension) = 0;

    public:
        std::vector<shared_ptr<hittable>> objects;
};

#endif