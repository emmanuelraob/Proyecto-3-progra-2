#include <gtest/gtest.h>
#include <material.hh>
#include <sphere.hh>

#include <vec3.hh>

// sphere() {}
// Keylor
// Prueba del constructor por defecto verdadera, a traves del mat_ptr, lo
// compara para ver si es null
TEST(Sphere_Test, Default_Constructor_True) {
  sphere sphere_aux = sphere();

  EXPECT_EQ(sphere_aux.mat_ptr, nullptr);
}

// sphere() {}
// Keylor
// Prueba del constructor por defecto false, a traves del mat_ptr, comparandolo
// con un mat_ptr creado
TEST(Sphere_Test, Default_Constructor_False) {
  sphere sphere_aux = sphere();

  auto material_aux = make_shared<lambertian>(color(0.4, 0.2, 0.1));

  EXPECT_NE(sphere_aux.mat_ptr, material_aux);
}

// sphere(point3 cen, double r, shared_ptr<material> m);
// Keylor
// Prueba del constructor con parametros, comprobando el valor de los parametros
// del sphere que se le dieron
TEST(Sphere_Test, Constructor_True) {

  point3 point_aux(0, 0, 0);
  double r_aux = 0.5;
  auto material_aux = make_shared<lambertian>(color(0.4, 0.2, 0.1));

  sphere sphere_aux = sphere(point_aux, r_aux, material_aux);

  // EXPECT_EQ(sphere_aux.center, point_aux); No se puede usar el point para
  // comparar porque falla el gtest
  EXPECT_EQ(sphere_aux.radius, r_aux);
  EXPECT_EQ(sphere_aux.mat_ptr, material_aux);
}

/*
Caminos a probar
if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
}
*/

// Emmanuel
// discriminante < 0
TEST(Sphere_Test, hit_discriminante_menor_cero) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(5, 0, 0), 1.0, material);

  // ray/
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = 0.001;
  auto t_max = infinity;

  hit_record rec;

  EXPECT_FALSE(sphere_aux.hit(r, t_min, t_max, rec));
}

// Emmanuel
// discriminante > 0
// segundo if 01
// tercer if 01
TEST(Sphere_Test, hit_cerouno_cerouno) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(0, 0, 0), 1.0, material);
  // ray
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = -5;
  auto t_max = -2;

  hit_record rec;

  EXPECT_FALSE(sphere_aux.hit(r, t_min, t_max, rec));
}

/*Keylor
Discriminante > 0
Segundo if: 00
Tercer if: No entra
*/
TEST(Sphere_Test, hit_00) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(0, 0, 0), 1.0, material);
  // ray
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = -1;
  auto t_max = -1;

  hit_record rec;

  EXPECT_TRUE(sphere_aux.hit(r, t_min, t_max, rec));
}

/*Keylor
Discriminante > 0
Segundo if: 10
Tercer if: 10
*/
TEST(Sphere_Test, Hit_10_10) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(0, 0, 0), 1.0, material);
  // ray
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = 50;
  auto t_max = 100;

  hit_record rec;

  EXPECT_FALSE(sphere_aux.hit(r, t_min, t_max, rec));
}

/*Keylor
Discriminante > 0
Segundo if: 10
Tercer if: 01
*/
TEST(Sphere_Test, hit_10_01) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(0, 0, 0), 1.0, material);
  // ray
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = 0.0;
  auto t_max = 0.0;

  hit_record rec;

  EXPECT_FALSE(sphere_aux.hit(r, t_min, t_max, rec));
}

/*Keylor
Discriminante > 0
Segundo if: 10
Tercer if: 00
*/
TEST(Sphere_Test, hit_10_00) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(0, 0, 0), 1.0, material);
  // ray
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = 0.001;
  auto t_max = infinity;

  hit_record rec;

  EXPECT_TRUE(sphere_aux.hit(r, t_min, t_max, rec));
}

/*Keylor
Discriminante > 0
Segundo if: 11
Tercer if: 01
*/
TEST(Sphere_Test, hit_11_01) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(0, 0, 0), 1.0, material);
  // ray
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = 0.001;
  auto t_max = -2;

  hit_record rec;

  EXPECT_FALSE(sphere_aux.hit(r, t_min, t_max, rec));
}

/*Keylor
Discriminante > 0
Segundo if: 11
Tercer if: 11
*/
TEST(Sphere_Test, hit_11_11) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(0, 0, 0), 1.0, material);
  // ray
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = 5;
  auto t_max = -100;

  hit_record rec;

  EXPECT_FALSE(sphere_aux.hit(r, t_min, t_max, rec));
}

/*Keylor
Discriminante > 0
Segundo if: 01
Tercer if: 01
*/
TEST(Sphere_Test, hit_01_01) {
  auto material = make_shared<lambertian>(color(0.4, 0.2, 0.1));
  sphere sphere_aux(point3(0, 0, 0), 1.0, material);
  // ray
  ray r(point3(0, 0, 0), vec3(0, 1, 0));

  auto t_min = -5;
  auto t_max = -2;

  hit_record rec;

  EXPECT_FALSE(sphere_aux.hit(r, t_min, t_max, rec));
}
