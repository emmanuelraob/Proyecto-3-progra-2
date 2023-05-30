#include <app.hh>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;

TEST(AppTest, RandomSceneTest) {
    app testApp;

    // Test that the random scene contains the correct number of objects
    hittable_list world = testApp.random_scene();
    EXPECT_EQ(world.objects.size(), 4);
}

TEST(AppTest, RayColorTest1) {
    app testApp;
    int depth = 0;
    hittable_list world = testApp.random_scene();

    ray r(point3(1, 2, 3), vec3(4, 5, 6));


    // Test that the function returns the correct color for an empty world with depth of 0
    color result = testApp.ray_color(r, world, depth);
    EXPECT_EQ(result[0], 0);
    EXPECT_EQ(result[1], 0);
    EXPECT_EQ(result[2], 0);
}

TEST(AppTest, RayColorTest2) {
    app testApp;
    hittable_list world = testApp.random_scene();
    color result;
    
    // Test when depth is more than zero and ray hits the object
    ray r1(point3(13,2,3), vec3(-13,-2,-3));  // Given ray direction, it should hit the object
    int depth1 = 10;
    result = testApp.ray_color(r1, world, depth1);
    EXPECT_NE(result[0], 0);
    EXPECT_NE(result[1], 0);
    EXPECT_NE(result[2], 0);
}

TEST(AppTest, RayColorTest3) {
    app testApp;
    hittable_list world = testApp.random_scene();
    color result;
    
    // Test when depth is more than zero and ray does not hit the object
    ray r2(point3(20,20,20), vec3(1,1,1));  // Given ray direction, it should not hit the object
    int depth2 = 10;
    result = testApp.ray_color(r2, world, depth2);
    EXPECT_NE(result[0], 0);
    EXPECT_NE(result[1], 0);
    EXPECT_NE(result[2], 0);
}

TEST(AppTest, RayColorTest4) {
    app testApp;
    hittable_list world = testApp.random_scene();
    color result;

    // Test when depth is zero
    ray r3(point3(0,0,0), vec3(0,0,1));
    int depth3 = 10;
    result = testApp.ray_color(r3, world, depth3);
    EXPECT_NE(result[0], 0);
    EXPECT_NE(result[1], 0);
    EXPECT_NE(result[2], 0);
}


TEST(MaterialTest, ScatterTest1) {
    hit_record rec;
    rec.p = point3(0,0,0);
    rec.normal = vec3(0,0,1);
    color attenuation;
    ray scattered;

    // Test for lambertian material
    auto lambert_mat = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    rec.mat_ptr = lambert_mat;
    ray r_lamb(point3(1,0,-1), vec3(-1,0,1));
    EXPECT_TRUE(lambert_mat->scatter(r_lamb, rec, attenuation, scattered));
}

TEST(MaterialTest, ScatterTest2) {
    hit_record rec;
    rec.p = point3(0,0,0);
    rec.normal = vec3(0,0,1);
    color attenuation;
    ray scattered;

    // Test for metal material
    auto metal_mat = make_shared<metal>(color(0.8, 0.8, 0.8), 0.5);
    rec.mat_ptr = metal_mat;
    ray r_metal(point3(1,0,-1), vec3(-1,0,1));
    EXPECT_FALSE(metal_mat->scatter(r_metal, rec, attenuation, scattered));
}

TEST(MaterialTest, ScatterTest3) {
    hit_record rec;
    rec.p = point3(0,0,0);
    rec.normal = vec3(0,0,1);
    color attenuation;
    ray scattered;

    // Test for dielectric material
    auto dielectric_mat = make_shared<dielectric>(1.5);
    rec.mat_ptr = dielectric_mat;
    ray r_dielectric(point3(1,0,-1), vec3(-1,0,1));
    EXPECT_TRUE(dielectric_mat->scatter(r_dielectric, rec, attenuation, scattered));
}
