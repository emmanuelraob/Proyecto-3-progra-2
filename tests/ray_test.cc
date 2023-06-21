#include <gtest/gtest.h>
#include <ray.hh>

// Dariel
// Prueba que se obtenga correctamente el origen asignado
TEST(RayTest, Getting_Ray_Origin_True) {

  vec3 orig1 = vec3(1, 3, 0);
  ray rayo1 = ray(orig1, orig1);
  EXPECT_TRUE(compare_vectors(rayo1.origin(), orig1));

  vec3 orig2 = vec3(4, 1, 0.5);
  ray rayo2 = ray(orig2, orig2);
  EXPECT_TRUE(compare_vectors(rayo2.origin(), orig2));
}

// Dariel
// Prueba que se obtenga un origen distinto de un vector al azar
TEST(RayTest, Getting_Ray_Origin_False) {

  vec3 orig1 = vec3(1, 0, 0);
  ray rayo1 = ray(orig1, orig1);
  EXPECT_FALSE(compare_vectors(rayo1.origin(), vec3(2, 1, 3)));

  vec3 orig2 = vec3(1 / 3.0, 5, -3 / 4.0);
  ray rayo2 = ray(orig2, orig2);
  EXPECT_FALSE(compare_vectors(rayo2.origin(), vec3(1, 2, 3)));
}

// Dariel
// Prueba que se obtenga correctamente la direccion asignada
TEST(RayTest, Getting_Ray_Direction_True) {

  vec3 dir1 = vec3(1, 3, 0);
  ray rayo1 = ray(dir1, dir1);
  EXPECT_TRUE(compare_vectors(rayo1.origin(), dir1));

  vec3 dir2 = vec3(4, 1, 0.5);
  ray rayo2 = ray(dir2, dir2);
  EXPECT_TRUE(compare_vectors(rayo2.origin(), dir2));
}

// Prueba que se obtenga una direccion distinta de un vector al azar
TEST(RayTest, Getting_Ray_Direction_False) {

  vec3 dir1 = vec3(1, 0, 0);
  ray rayo1 = ray(dir1, dir1);
  EXPECT_FALSE(compare_vectors(rayo1.direction(), vec3(2, 1, 1)));

  vec3 dir2 = vec3(1 / 3.0, 5, -3 / 4.0);
  ray rayo2 = ray(dir2, dir2);
  EXPECT_FALSE(compare_vectors(rayo2.direction(), vec3(2, 2, 3)));
}

// Dariel
// Prueba que se genere el vector hacia donde apunta el rayo con cierta longitud
// t correctamente
TEST(RayTest, Getting_Ray_Pointing_At_True) {

  vec3 orig1 = vec3(0, 0, 0);
  vec3 dir1 = vec3(1, 0, 0);
  ray rayo1 = ray(orig1, dir1);
  double t1 = 2.0;

  EXPECT_TRUE(compare_vectors(rayo1.at(t1), vec3(2, 0, 0)));

  vec3 orig2 = vec3(23, 2.3, 0.23);
  vec3 dir2 = vec3(2, 1, 0);
  ray rayo2 = ray(orig2, dir2);
  double t2 = 5.0;

  EXPECT_TRUE(compare_vectors(rayo2.at(t2), vec3(33, 7.3, 0.23)));
}

// Dariel
// Prueba que el vector hacia donde apunta el rayo con una distancia t sea
// distinta de un vector random
TEST(RayTest, Getting_Ray_Pointing_At_False) {

  vec3 orig1 = vec3(0, 0, 0);
  vec3 dir1 = vec3(1, 0, 0);
  ray rayo1 = ray(orig1, dir1);
  double t1 = 2.0;

  EXPECT_FALSE(compare_vectors(rayo1.at(t1), vec3(1, 5, 0.333)));

  vec3 orig2 = vec3(23, 2.3, 0.23);
  vec3 dir2 = vec3(2, 1, 0);
  ray rayo2 = ray(orig2, dir2);
  double t2 = 5.0;

  EXPECT_FALSE(compare_vectors(rayo2.at(t2), vec3(3, 3.7, 23)));
}

// Emmanel
// estas pruebas son para aumentar el branch coverage
// uso de chatgpt para ello, pasan a la primera sin necesidad de hacer cambios
// mayores

TEST(CompareRaysTest, same_origin_and_direction) {
  ray ray1(point3(1, 2, 3), vec3(4, 5, 6));
  ray ray2(point3(1, 2, 3), vec3(4, 5, 6));
  EXPECT_TRUE(compare_rays(ray1, ray2));
}

TEST(CompareRaysTest, same_origin_different_direction) {
  ray ray1(point3(1, 2, 3), vec3(4, 5, 6));
  ray ray2(point3(1, 2, 3), vec3(7, 8, 9));
  EXPECT_FALSE(compare_rays(ray1, ray2));
}

TEST(CompareRaysTest, different_origin_same_direction) {
  ray ray1(point3(1, 2, 3), vec3(4, 5, 6));
  ray ray2(point3(7, 8, 9), vec3(4, 5, 6));
  EXPECT_FALSE(compare_rays(ray1, ray2));
}

TEST(CompareRaysTest, different_origin_and_direction) {
  ray ray1(point3(1, 2, 3), vec3(4, 5, 6));
  ray ray2(point3(7, 8, 9), vec3(10, 11, 12));
  EXPECT_FALSE(compare_rays(ray1, ray2));
}