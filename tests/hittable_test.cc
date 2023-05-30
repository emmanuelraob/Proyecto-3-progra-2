#include <gtest/gtest.h>
#include <hittable.hh>
#include <ray.hh>
#include <vec3.hh>
#include <gmock/gmock.h>

//Emmanuel 
//prueba set normal face con normal negativa    
TEST(hittable,set_normal_face){
    hit_record record;
    ray r = ray(point3(0,0,0), vec3(1,0,0));
    vec3 outward_normal = vec3(1,0,0);
    record.set_face_normal(r,outward_normal);
    EXPECT_FALSE(record.front_face);
    EXPECT_EQ(record.normal[0],-1);
}

//Emmanuel 
//prueba set normal face con normal positiva 
TEST(hittable,set_normal_face_outward_normal){
    hit_record record;
    ray r = ray(point3(0,0,0), vec3(1,0,0));
    vec3 outward_normal = vec3(-1,0,0);
    record.set_face_normal(r,outward_normal);
    EXPECT_TRUE(record.front_face);
    EXPECT_EQ(record.normal[0],-1);
}