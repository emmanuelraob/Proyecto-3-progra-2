#include <gtest/gtest.h>
#include <rtweekend.hh>
#include <hittable.hh>
#include <hittable_list.hh>
#include <material.hh>
#include <sphere.hh>
#include <ray.hh>


//Emmanuel
//prueba del constructor de la hittable list, crea un vector vacio
TEST(hittable_list_test,constructor_valido){
    auto list = hittable_list();
    EXPECT_TRUE(list.objects.empty());
}


//Emmanuel 
//prueba de la funcion add, crea una lista y le anade algo nulo
TEST(hittable_list_test,add_nullptr){
    auto list = hittable_list();
    list.add(nullptr);
    EXPECT_FALSE(list.objects.empty());
    EXPECT_EQ(list.objects[0],nullptr);
}

//Emmanuel 
//prueba de la funcion add, crea una lista y le anade algo valido
TEST(hittable_list_test,add){
    auto list = hittable_list();
    auto object = make_shared<sphere>(point3(0,0,0), 1.0, nullptr);
    list.add(object);
    EXPECT_FALSE(list.objects.empty());
    EXPECT_EQ(list.objects[0],object);
}


//Emmanuel 
//prueba constructor hittable list con objeto nulo
TEST(hittable_list_test,constructor_object_null){
    shared_ptr<hittable> null_object = nullptr;
    auto list = hittable_list(null_object);
    EXPECT_FALSE(list.objects.empty());
    EXPECT_EQ(list.objects[0], null_object);
}

//Emmanuel 
//prueba constructor hittable list con objeto nulo
TEST(hittable_list_test,constructor_object){
    auto object = make_shared<sphere>(point3(0, 0, 0), 1.0, nullptr);
    auto list = hittable_list(object);
    EXPECT_FALSE(list.objects.empty());
    EXPECT_EQ(list.objects[0], object);
}

//Emmanuel 
//prueba funcion clear, se crea una lista y se limpa
TEST(hittable_list_test,clear){
    shared_ptr<hittable> object;
    auto list = hittable_list(object);
    EXPECT_FALSE(list.objects.empty());
    list.add(object);
    list.add(object);          
    EXPECT_FALSE(list.objects.empty());
    list.clear();
    EXPECT_TRUE(list.objects.empty());
}

//Emmanuel 
//prueba funcion hit, se prueba la imagen donde colisiona con el suelo
TEST(hittable_list_test,hit){
    auto sphere_ptr = make_shared<sphere>(point3(0, 0, 0), 1.0, nullptr);
    ray r(point3(0, 0, -1), vec3(0, 0, 1));
    hit_record rec;   
    hittable_list list;
    list.add(sphere_ptr);
    EXPECT_TRUE(list.hit(r, 0, infinity, rec));
}

//Emmanuel 
//prueba funcion hit, se prueba la imagen donde no colisiona lo existente
TEST(hittable_list_test,no_hit){
    //escena
    hittable_list world;
    
    auto material = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(20, 20, 20), 0.1, material));

    //ray
    ray r (point3(0,0,0),vec3(0,2,0));

    hit_record rec;   
    
    EXPECT_FALSE(world.hit(r, 0.001, infinity, rec));
}

//Emmanuel 
//prueba funcion hit, se prueba la imagen sin objetos por completo
TEST(hittable_list_test,no_hit_no_list){
    ray r(point3(0, 0, -1), vec3(0, 0, 1));
    hittable_list list;
    hit_record rec;
    EXPECT_FALSE(list.hit(r, 0, infinity, rec));
}