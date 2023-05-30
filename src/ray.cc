#include <ray.hh>

bool compare_rays(ray ray1, ray ray2){
    return compare_vectors(ray1.origin(), ray2.origin()) && compare_vectors(ray1.direction(), ray2.direction());
}