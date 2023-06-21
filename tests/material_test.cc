#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <material.hh>
using namespace std;

// useful samples start
vec3 vec3_object_1(0.7, 0.9, 0.6);
vec3 vec3_object_2(1.4, 1.7, 1.9);
vec3 &vec3_reference_1 = vec3_object_1;
vec3 &vec3_reference_2 = vec3_object_2;

ray ray_object1(vec3_reference_1, vec3_reference_2);

auto ptr_to_material_1 = make_shared<metal>(vec3_reference_1, 2.2);
hit_record hit_record_object_1 = {vec3_object_1, vec3_object_2,
                                  ptr_to_material_1, 0.5, true};

bool compare_hit_record(const hit_record &a, const hit_record &b) {
  bool same_p = compare_vectors(a.p, b.p);
  bool same_normal = compare_vectors(a.normal, b.normal);
  bool same_mat_ptr = a.mat_ptr.get() == b.mat_ptr.get();
  bool same_t = a.t == b.t;
  bool same_front_face = a.front_face == b.front_face;
  return (same_p && same_normal && same_mat_ptr && same_t && same_front_face);
}
// useful samples end

// mocking tools start
class mock_material : public material {
public:
  MOCK_METHOD(bool, scatter,
              (const ray &r_in, const hit_record &rec, color &attenuation,
               ray &scattered),
              (const, override));
};

// class MaterialTest : public ::testing::Test {
// protected:
//    void SetUp() override {
//       mock_material_obj = new mock_material;
//    }
//
//    void TearDown() override {
//       delete mock_material_obj;
//    }

//   mock_material* mock_material_obj;
//};
// mocking tools end

TEST(MaterialTest_Test, MaterialConstructorTest) {
  // mock_material* mock_material_obj =
  // dynamic_cast<mock_material*>(mock_material_obj);
}

TEST(MaterialTest, MaterialScatterTest) {}

// class lambertian
// constructor test
TEST(LambertianTest, LambertianConstructorTest) {
  vec3 &color = vec3_object_1;
  lambertian lambertian_obj(color);
  vec3 lambertian_albedo = lambertian_obj.albedo;

  EXPECT_TRUE(compare_vectors(lambertian_albedo, color));
}

// first arg evaluation scatter (true if)
TEST(LambertianTest, LambertianScatterTest_TrueIf_1_Argument) {
  vec3 vec3_object_Lambertian_TrueIf_Argument(0.000001, 0.000001, 0.000001);
  vec3 &vec3_reference_Lambertian_TrueIf_Argument =
      vec3_object_Lambertian_TrueIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_TrueIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &r_in_ref_to_expect = ray_object1;

  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));
}

// second arg evaluation scatter (true if)
TEST(LambertianTest, LambertianScatterTest_TrueIf_2_Argument) {
  vec3 vec3_object_Lambertian_TrueIf_Argument(0.000001, 0.000001, 0.000001);
  vec3 &vec3_reference_Lambertian_TrueIf_Argument =
      vec3_object_Lambertian_TrueIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_TrueIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  hit_record &rec_ref_to_expect = rec_obj;

  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));
}

// third arg evaluation scatter (true if)
TEST(LambertianTest, LambertianScatterTest_TrueIf_3_Argument) {
  vec3 vec3_object_Lambertian_TrueIf_Argument(0.000001, 0.000001, 0.000001);
  vec3 &vec3_reference_Lambertian_TrueIf_Argument =
      vec3_object_Lambertian_TrueIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_TrueIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect = lambertian_obj.albedo;

  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));
}

// fourth arg evaluation scatter (true if)
TEST(LambertianTest, LambertianScatterTest_TrueIf_4_Argument) {
  vec3 vec3_object_Lambertian_TrueIf_Argument(0.000001, 0.000001, 0.000001);
  vec3 &vec3_reference_Lambertian_TrueIf_Argument =
      vec3_object_Lambertian_TrueIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_TrueIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &scattered_ref_to_expect = ray_object1;
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir = rec.normal;

  EXPECT_TRUE(compare_vectors(scattered.orig, scattered_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(scattered.dir, scattered_ref_to_expect.dir));
}

// all arg evaluation scatter (true if)
TEST(LambertianTest, LambertianScatterTest_TrueIf_ALL_Argument) {
  vec3 vec3_object_Lambertian_TrueIf_Argument(0.000001, 0.000001, 0.000001);
  vec3 &vec3_reference_Lambertian_TrueIf_Argument =
      vec3_object_Lambertian_TrueIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_TrueIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &r_in_ref_to_expect = ray_object1;
  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));

  hit_record &rec_ref_to_expect = rec_obj;
  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect = lambertian_obj.albedo;
  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));

  ray &scattered_ref_to_expect = ray_object1;
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir = rec.normal;
  EXPECT_TRUE(compare_vectors(scattered.orig, scattered_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(scattered.dir, scattered_ref_to_expect.dir));
}

// first arg evaluation scatter (false if)
TEST(LambertianTest, LambertianScatterTest_FalseIf_1_Argument) {
  vec3 vec3_object_Lambertian_FalseIf_Argument(9999, 9999, 9999);
  vec3 &vec3_reference_Lambertian_FalseIf_Argument =
      vec3_object_Lambertian_FalseIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_FalseIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &r_in_ref_to_expect = ray_object1;

  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));
}

// second arg evaluation scatter (false if)
TEST(LambertianTest, LambertianScatterTest_FalseIf_2_Argument) {
  vec3 vec3_object_Lambertian_FalseIf_Argument(9999, 9999, 9999);
  vec3 &vec3_reference_Lambertian_FalseIf_Argument =
      vec3_object_Lambertian_FalseIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_FalseIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  hit_record &rec_ref_to_expect = rec_obj;

  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));
}

// third arg evaluation scatter (false if)
TEST(LambertianTest, LambertianScatterTest_FalseIf_3_Argument) {
  vec3 vec3_object_Lambertian_FalseIf_Argument(9999, 9999, 9999);
  vec3 &vec3_reference_Lambertian_FalseIf_Argument =
      vec3_object_Lambertian_FalseIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_FalseIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect = lambertian_obj.albedo;

  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));
}

// fourth arg evaluation scatter (false if)
TEST(LambertianTest, LambertianScatterTest_FalseIf_4_Argument) {
  vec3 vec3_object_Lambertian_FalseIf_Argument(9999, 9999, 9999);
  vec3 &vec3_reference_Lambertian_FalseIf_Argument =
      vec3_object_Lambertian_FalseIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_FalseIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &scattered_ref_to_expect = ray_object1;
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir = rec.normal + random_unit_vector();

  EXPECT_TRUE(compare_vectors(scattered.orig, scattered_ref_to_expect.orig));
  EXPECT_DOUBLE_EQ(scattered.dir[0], scattered_ref_to_expect.dir[0]);
  EXPECT_DOUBLE_EQ(scattered.dir[1], scattered_ref_to_expect.dir[1]);
  EXPECT_DOUBLE_EQ(scattered.dir[2], scattered_ref_to_expect.dir[2]);
}

// all arg evaluation scatter (false if)
TEST(LambertianTest, LambertianScatterTest_FalseIf_ALL_Argument) {
  vec3 vec3_object_Lambertian_FalseIf_Argument(9999, 9999, 9999);
  vec3 &vec3_reference_Lambertian_FalseIf_Argument =
      vec3_object_Lambertian_FalseIf_Argument;

  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_Lambertian_FalseIf_Argument,
                        ptr_to_material_1, 0.5, true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  lambertian lambertian_obj(color);

  bool scatter_result =
      lambertian_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &r_in_ref_to_expect = ray_object1;
  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));

  hit_record &rec_ref_to_expect = rec_obj;
  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect = lambertian_obj.albedo;
  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));

  ray &scattered_ref_to_expect = ray_object1;
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir = rec.normal + random_unit_vector();
  EXPECT_TRUE(compare_vectors(scattered.orig, scattered_ref_to_expect.orig));
  EXPECT_DOUBLE_EQ(scattered.dir[0], scattered_ref_to_expect.dir[0]);
  EXPECT_DOUBLE_EQ(scattered.dir[1], scattered_ref_to_expect.dir[1]);
  EXPECT_DOUBLE_EQ(scattered.dir[2], scattered_ref_to_expect.dir[2]);
}

// class metal
// constructor f < 1
TEST(MetalTest, MetalConstructorTest_TrueIf) {
  vec3 &color = vec3_object_1;
  double fuzz = 0.99;

  metal metal_obj(color, fuzz);

  EXPECT_TRUE(compare_vectors(metal_obj.albedo, color));
  EXPECT_EQ(metal_obj.fuzz, fuzz);
}

// constructor f >= 1
TEST(MetalTest, MetalConstructorTest_FalseIf) {
  vec3 &color = vec3_object_1;
  double fuzz = 1.3;

  metal metal_obj(color, fuzz);

  EXPECT_TRUE(compare_vectors(metal_obj.albedo, color));
  EXPECT_EQ(metal_obj.fuzz, 1);
}

// first arg evaluation scatter
TEST(MetalTest, Metal_ScatterTest_1_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  metal metal_obj(color, 1.5);

  bool scatter_result = metal_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_EQ(scatter_result, (dot(scattered.dir, rec.normal) > 0));

  ray &r_in_ref_to_expect = ray_object1;

  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));
}

// second arg evaluation scatter
TEST(MetalTest, Metal_ScatterTest_2_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  metal metal_obj(color, 1.5);

  bool scatter_result = metal_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_EQ(scatter_result, (dot(scattered.dir, rec.normal) > 0));

  hit_record &rec_ref_to_expect = rec_obj;
  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));
}

// third arg evaluation scatter
TEST(MetalTest, Metal_ScatterTest_3_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  metal metal_obj(color, 1.5);

  bool scatter_result = metal_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_EQ(scatter_result, (dot(scattered.dir, rec.normal) > 0));

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect = metal_obj.albedo;

  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));
}

// fourth arg evaluation scatter
TEST(MetalTest, Metal_ScatterTest_4_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  metal metal_obj(color, 1.5);

  bool scatter_result = metal_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_EQ(scatter_result, (dot(scattered.dir, rec.normal) > 0));

  ray &scattered_ref_to_expect = ray_object1;
  vec3 reflected = reflect(unit_vector(r_in.dir), rec.normal);
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir =
      reflected + metal_obj.fuzz * random_in_unit_sphere();

  EXPECT_TRUE(compare_vectors(scattered.dir, scattered_ref_to_expect.dir));
  EXPECT_DOUBLE_EQ(scattered.dir[0], scattered_ref_to_expect.dir[0]);
  EXPECT_DOUBLE_EQ(scattered.dir[1], scattered_ref_to_expect.dir[1]);
  EXPECT_DOUBLE_EQ(scattered.dir[2], scattered_ref_to_expect.dir[2]);
}

// all arg evaluation scatter
TEST(MetalTest, Metal_ScatterTest_ALL_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  vec3 &color = vec3_object_2;
  metal metal_obj(color, 1.5);

  bool scatter_result = metal_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_EQ(scatter_result, (dot(scattered.dir, rec.normal) > 0));

  ray &r_in_ref_to_expect = ray_object1;
  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));

  hit_record &rec_ref_to_expect = rec_obj;
  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect = metal_obj.albedo;
  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));

  ray &scattered_ref_to_expect = ray_object1;
  vec3 reflected = reflect(unit_vector(r_in.dir), rec.normal);
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir =
      reflected + metal_obj.fuzz * random_in_unit_sphere();
  EXPECT_TRUE(compare_vectors(scattered.dir, scattered_ref_to_expect.dir));
  EXPECT_DOUBLE_EQ(scattered.dir[0], scattered_ref_to_expect.dir[0]);
  EXPECT_DOUBLE_EQ(scattered.dir[1], scattered_ref_to_expect.dir[1]);
  EXPECT_DOUBLE_EQ(scattered.dir[2], scattered_ref_to_expect.dir[2]);
}

// class dielectric
// constructor test
TEST(DielectricTest, DielectricConstructorTest) {
  double ir = 0.8;
  dielectric dielectric_obj(ir);

  EXPECT_EQ(dielectric_obj.ir, ir);
}

// first arg evaluation scatter (true if)
TEST(DielectricTest, DielectricScatterTest_TrueIf_1_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        false};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &r_in_ref_to_expect = ray_object1;
  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));
}

// second arg evaluation scatter (true if)
TEST(DielectricTest, DielectricScatterTest_TrueIf_2_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        false};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  hit_record &rec_ref_to_expect = rec_obj;
  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));
}

// third arg evaluation scatter (true if)
TEST(DielectricTest, DielectricScatterTest_TrueIf_3_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        false};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect[0] = 1.0;
  attenuation_ref_to_expect[1] = 1.0;
  attenuation_ref_to_expect[2] = 1.0;

  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));
}

// fourth arg evaluation scatter (true if)
TEST(DielectricTest, DielectricScatterTest_TrueIf_4_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        false};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;
  vec3 unit_direction = unit_vector(r_in.direction());
  ray &scattered_ref_to_expect = ray_object1;
  vec3 direction = reflect(unit_direction, rec.normal);
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir = direction;

  EXPECT_TRUE(compare_vectors(scattered.orig, scattered_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(scattered.dir, scattered_ref_to_expect.dir));
}

// all arg evaluation scatter (true if)
TEST(DielectricTest, DielectricScatterTest_TrueIf_ALL_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        false};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &r_in_ref_to_expect = ray_object1;
  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));

  hit_record &rec_ref_to_expect = rec_obj;
  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect[0] = 1.0;
  attenuation_ref_to_expect[1] = 1.0;
  attenuation_ref_to_expect[2] = 1.0;
  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));

  double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;
  vec3 unit_direction = unit_vector(r_in.direction());
  ray &scattered_ref_to_expect = ray_object1;
  vec3 direction = reflect(unit_direction, rec.normal);
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir = direction;
  EXPECT_TRUE(compare_vectors(scattered.orig, scattered_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(scattered.dir, scattered_ref_to_expect.dir));
}

// first arg evaluation scatter (false if)
TEST(DielectricTest, DielectricScatterTest_FalseIf_1_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &r_in_ref_to_expect = ray_object1;
  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));
}

// second arg evaluation scatter (false if)
TEST(DielectricTest, DielectricScatterTest_FalseIf_2_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  hit_record &rec_ref_to_expect = rec_obj;
  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));
}

// third arg evaluation scatter (false if)
TEST(DielectricTest, DielectricScatterTest_FalseIf_3_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect[0] = 1.0;
  attenuation_ref_to_expect[1] = 1.0;
  attenuation_ref_to_expect[2] = 1.0;

  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));
}

// fourth arg evaluation scatter (false if)
TEST(DielectricTest, DielectricScatterTest_FalseIf_4_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;
  vec3 unit_direction = unit_vector(r_in.direction());
  ray &scattered_ref_to_expect = ray_object1;
  vec3 direction = refract(unit_direction, rec.normal, refraction_ratio);
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir = direction;

  EXPECT_TRUE(compare_vectors(scattered.orig, scattered_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(scattered.dir, scattered_ref_to_expect.dir));
}

// all arg evaluation scatter (false if)
TEST(DielectricTest, DielectricScatterTest_FalseIf_ALL_Argument) {
  ray &r_in = ray_object1;
  hit_record rec_obj = {vec3_object_1, vec3_object_2, ptr_to_material_1, 0.5,
                        true};
  hit_record &rec = rec_obj;
  vec3 &attenuation = vec3_object_1;
  ray &scattered = ray_object1;

  double ir = 0.5;
  dielectric dielectric_obj(0.5);

  bool scatter_result =
      dielectric_obj.scatter(r_in, rec, attenuation, scattered);
  EXPECT_TRUE(scatter_result);

  ray &r_in_ref_to_expect = ray_object1;
  EXPECT_TRUE(compare_vectors(r_in.orig, r_in_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(r_in.dir, r_in_ref_to_expect.dir));

  hit_record &rec_ref_to_expect = rec_obj;
  EXPECT_TRUE(compare_hit_record(rec, rec_ref_to_expect));

  vec3 &attenuation_ref_to_expect = vec3_object_1;
  attenuation_ref_to_expect[0] = 1.0;
  attenuation_ref_to_expect[1] = 1.0;
  attenuation_ref_to_expect[2] = 1.0;
  EXPECT_TRUE(compare_vectors(attenuation, attenuation_ref_to_expect));

  double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;
  vec3 unit_direction = unit_vector(r_in.direction());
  ray &scattered_ref_to_expect = ray_object1;
  vec3 direction = refract(unit_direction, rec.normal, refraction_ratio);
  scattered_ref_to_expect.orig = rec.p;
  scattered_ref_to_expect.dir = direction;
  EXPECT_TRUE(compare_vectors(scattered.orig, scattered_ref_to_expect.orig));
  EXPECT_TRUE(compare_vectors(scattered.dir, scattered_ref_to_expect.dir));
}

// test calc from reflectance
TEST(DielectricTest, DielectricReflectanceTest) {
  dielectric dielectric_obj(8.0);
  double reflectance_result = dielectric_obj.reflectance(0.4, 0.2);

  double step_1_reflectance = (1 - 0.2) / (1 + 0.2);
  step_1_reflectance *= step_1_reflectance;
  double reflectance_result_to_expect =
      step_1_reflectance + (1 - step_1_reflectance) * pow((1 - 0.4), 5);
  EXPECT_DOUBLE_EQ(reflectance_result, reflectance_result_to_expect);
}
