#include <gtest/gtest.h>
#include <vec3.hh>

// Dariel
// Prueba que el valor X obtenido sea valido
TEST(Vec3Test, Getting_X_True) {

  vec3 u1 = vec3(2, 0, 0);
  EXPECT_EQ(u1.x(), 2);

  vec3 u2 = vec3(5, 6, 1);
  EXPECT_EQ(u2.x(), 5);
}

// Dariel
// Prueba que el valor X obtenido sea distinto de otro seleccionado
TEST(Vec3Test, Getting_X_False) {

  vec3 u1 = vec3(2, 0, 0);
  EXPECT_NE(u1.x(), 0);

  vec3 u2 = vec3(5, 6, 1);
  EXPECT_NE(u2.x(), 1);
}

// Dariel
// Prueba que el valor Y obtenido sea valido
TEST(Vec3Test, Getting_Y_True) {

  vec3 u1 = vec3(3, 29, 177);
  EXPECT_EQ(u1.y(), 29);

  vec3 u2 = vec3(1, 4 / 5.0, 1);
  EXPECT_EQ(u2.y(), 0.8);
}

// Dariel
// Prueba que el valor Y obtenido sea distinto de otro seleccionado
TEST(Vec3Test, Getting_Y_False) {

  vec3 u1 = vec3(3, 29, 177);
  EXPECT_NE(u1.y(), 28);

  vec3 u2 = vec3(1, 4 / 5.0, 1);
  EXPECT_NE(u2.y(), 0.8125);
}

// Dariel
// Prueba que el valor Z obtenido sea valido
TEST(Vec3Test, Getting_Z_True) {

  vec3 u1 = vec3(2, 0, 4);
  EXPECT_EQ(u1.z(), 4);

  vec3 u2 = vec3(5, 1, 0.75);
  EXPECT_EQ(u2.z(), 3 / 4.0);
}

// Dariel
// Prueba que el valor Z obtenido sea distinto de otro seleccionado
TEST(Vec3Test, Getting_Z_False) {

  vec3 u1 = vec3(2, 0, 4);
  EXPECT_NE(u1.z(), 5);

  vec3 u2 = vec3(5.77, 2, 1);
  EXPECT_NE(u2.z(), 7);
}

// Dariel
// Prueba la suma de vectores
TEST(Vec3Test, Suma) {
  vec3 u = vec3(1, 1, 2);
  vec3 v = vec3(6, 3, 1);
  vec3 w = vec3(2, 2, 2);
  vec3 z = vec3(1, 1, 1);

  vec3 add1 = u + v;
  vec3 add2 = u + w;
  vec3 add3 = u + z;
  vec3 add4 = v + w;
  vec3 add5 = v + z;
  vec3 add6 = w + z;

  EXPECT_TRUE(compare_vectors(add1, vec3(7, 4, 3)));
  EXPECT_TRUE(compare_vectors(add2, vec3(3, 3, 4)));
  EXPECT_TRUE(compare_vectors(add3, vec3(2, 2, 3)));
  EXPECT_TRUE(compare_vectors(add4, vec3(8, 5, 3)));
  EXPECT_TRUE(compare_vectors(add5, vec3(7, 4, 2)));
  EXPECT_TRUE(compare_vectors(add6, vec3(3, 3, 3)));
}

// Dariel
// Prueba la resta de vectores
TEST(Vec3Test, Resta) {

  vec3 u = vec3(1, 1, 2);
  vec3 v = vec3(6, 3, 1);
  vec3 w = vec3(2, 2, 2);
  vec3 z = vec3(1, 1, 1);

  vec3 sub1 = u - v;
  vec3 sub2 = u - w;
  vec3 sub3 = u - z;
  vec3 sub4 = v - w;
  vec3 sub5 = v - z;
  vec3 sub6 = w - z;

  EXPECT_TRUE(compare_vectors(sub1, vec3(-5, -2, 1)));
  EXPECT_TRUE(compare_vectors(sub2, vec3(-1, -1, 0)));
  EXPECT_TRUE(compare_vectors(sub3, vec3(0, 0, 1)));
  EXPECT_TRUE(compare_vectors(sub4, vec3(4, 1, -1)));
  EXPECT_TRUE(compare_vectors(sub5, vec3(5, 2, 0)));
  EXPECT_TRUE(compare_vectors(sub6, vec3(1, 1, 1)));
}

// Dariel
// Prueba el producto punto de vectores
TEST(Vec3Test, ProductoPunto) {

  vec3 u = vec3(1, 1, 2);
  vec3 v = vec3(6, 3, 1);
  vec3 w = vec3(2, 2, 2);
  vec3 z = vec3(1, 1, 1);

  vec3 add1 = u + v;

  EXPECT_EQ(dot(u, v), 11);
  EXPECT_EQ(dot(u, w), 8);
  EXPECT_EQ(dot(u, z), 4);
  EXPECT_EQ(dot(v, w), 20);
  EXPECT_EQ(dot(v, z), 10);
  EXPECT_EQ(dot(w, z), 6);

  EXPECT_TRUE(compare_vectors(add1, vec3(7, 4, 3)));
}

// Venus
// Prueba el producto cruz de vectores
TEST(Vec3Test, ProductoCruz) {

  vec3 u = vec3(1, 2, 3);
  vec3 v = vec3(-1, 1, 0);
  vec3 resultado = cross(u, v);

  EXPECT_TRUE(compare_vectors(resultado, vec3(-3, -3, 3)));

  vec3 w = vec3(1, -1, 2);
  vec3 z = vec3(2, 1, 3);
  vec3 resultado1 = cross(w, z);
  vec3 resultado2 = cross(u, w);

  EXPECT_TRUE(compare_vectors(resultado1, vec3(-5, 1, 3)));
  EXPECT_TRUE(compare_vectors(resultado2, vec3(7, 1, -3)));
}

// Venus
// Prueba la division de un vector entre un double
TEST(Vec3Test, Division) {
  vec3 u = vec3(1, 1, 2);
  vec3 v = vec3(6, 3, 1);
  vec3 w = vec3(2, 2, 2);
  vec3 z = vec3(1, 1, 1);

  vec3 div1 = u / 2;
  vec3 div2 = v / 3;
  vec3 div3 = w / 6;
  vec3 div4 = z / 4;

  EXPECT_TRUE(compare_vectors(div1, vec3(1 / 2.0, 1 / 2.0, 1)));
  EXPECT_TRUE(compare_vectors(div2, vec3(2, 1, 1 / 3.0)));
  EXPECT_TRUE(compare_vectors(div3, vec3(1 / 3.0, 1 / 3.0, 1 / 3.0)));
  EXPECT_TRUE(compare_vectors(div4, vec3(1 / 4.0, 1 / 4.0, 1 / 4.0)));
}

// Venus
// Prueba la multiplicacion entre un vector y un double o entre vectores
TEST(Vec3Test, Multiplicacion) {
  vec3 u = vec3(0, 2, -1);
  vec3 v = vec3(10, 1 / 2.0, -1 / 2.0);
  vec3 w = vec3(1 / 3.0, 4, 100);
  vec3 z = vec3(-13, 5, 8);

  vec3 mult1 = u * 2;
  vec3 mult2 = u * v;
  vec3 mult4 = z * 3;
  vec3 mult5 = z * u;

  EXPECT_TRUE(compare_vectors(mult1, vec3(0, 4, -2)));
  EXPECT_TRUE(compare_vectors(mult2, vec3(0, 1, 1 / 2.0)));
  EXPECT_TRUE(compare_vectors(mult4, vec3(-39, 15, 24)));
  EXPECT_TRUE(compare_vectors(mult5, vec3(0, 10, -8)));
}

// Dariel
// Prueba la refraccion
TEST(Vec3Test, Refraccion) {
  vec3 u1 = vec3(2, 1, 0);
  vec3 n1 = vec3(1, -3, 1);
  double eoe1 = 1;
  auto ct1 = fmin(dot(-u1, n1), 1.0);
  vec3 roper1 = eoe1 * (u1 + ct1 * n1);
  vec3 ropar1 = -sqrt(fabs(1.0 - roper1.length_squared())) * n1;
  vec3 res1 = roper1 + ropar1;

  vec3 u2 = vec3(2, 1, 0);
  vec3 n2 = vec3(1, -3, 1);
  double eoe2 = 1;
  auto ct2 = fmin(dot(-u2, n2), 1.0);
  vec3 roper2 = eoe2 * (u2 + ct2 * n2);
  vec3 ropar2 = -sqrt(fabs(1.0 - roper2.length_squared())) * n2;
  vec3 res2 = roper2 + ropar2;

  EXPECT_TRUE(compare_vectors(refract(u1, n1, eoe1), res1));
  EXPECT_TRUE(compare_vectors(refract(u2, n2, eoe2), res2));
}

// Dariel
// Prueba la longitud de un vector
TEST(Vec3Test, Longitud) {
  vec3 u = vec3(4, 3, 0);
  vec3 v = vec3(2, -3, 6);
  vec3 w = vec3(2, -3, sqrt(3));

  EXPECT_EQ(u.length(), 5);
  EXPECT_EQ(v.length(), 7);
  EXPECT_EQ(w.length(), 4);
}

// Dariel
// Prueba la longitud cuadrada de un vector
TEST(Vec3Test, LongitudCuadrada) {
  vec3 u = vec3(2, 5, 1);
  vec3 v = vec3(2, -3, 6);

  EXPECT_EQ(u.length_squared(), 30);
  EXPECT_EQ(v.length_squared(), 49);
}

// Venus
// Prueba la refleccion
TEST(Vec3Test, Reflect) {
  vec3 v = vec3(1, 4, 7);
  vec3 n = vec3(-3, 2, 6);
  vec3 resultado = reflect(v, n);

  EXPECT_TRUE(compare_vectors(resultado, vec3(283, -184, -557)));

  vec3 v1 = vec3(2, 1, -1);
  vec3 n1 = vec3(0, 4, 9);
  vec3 resultado1 = reflect(v1, n1);

  EXPECT_TRUE(compare_vectors(resultado1, vec3(2, 41, 89)));
}

// Dariel
// Prueba la generacion de un vector random
TEST(Vec3Test, Vector_Random) {

  vec3 u1;
  for (int i = 0; i < 100; i++) {
    u1 = u1.random();
    EXPECT_GE(u1.x(), 0);
    EXPECT_GE(u1.y(), 0);
    EXPECT_GE(u1.z(), 0);
    EXPECT_LE(u1.x(), 1);
    EXPECT_LE(u1.y(), 1);
    EXPECT_LE(u1.z(), 1);
  }
}

// Dariel
// Prueba la generacion de un vector random con un minimo y un maximo para sus
// dimensiones
TEST(Vec3Test, Vector_Random_Con_Parametros) {

  vec3 u1;
  double min = 4.0;
  double max = 20.0;
  for (int i = 0; i < 100; i++) {
    u1 = u1.random(min, max);
    EXPECT_GE(u1.x(), min);
    EXPECT_GE(u1.y(), min);
    EXPECT_GE(u1.z(), min);
    EXPECT_LE(u1.x(), max);
    EXPECT_LE(u1.y(), max);
    EXPECT_LE(u1.z(), max);
  }
}

// Dariel
// Prueba que todas las dimensiones de los vectores se encuentren cerca del 0
TEST(Vec3Test, Near_Zero_True) {

  vec3 u1 = vec3(1e-9, -1e-10, 1e-9);
  EXPECT_TRUE(u1.near_zero());

  vec3 u2 = vec3(11e-10, -1e-12, 2e-13);
  EXPECT_TRUE(u2.near_zero());

  vec3 u3 = vec3(0.5e-8, -0.05e-10, 1e-9);
  EXPECT_TRUE(u3.near_zero());
}

// Dariel
// Prueba que al menos una dimension de los vectores se encuentra un poco lejos
// del 0
TEST(Vec3Test, Near_Zero_False) {

  vec3 u1 = vec3(10000e-9, -1e-10, 1e-9);
  EXPECT_FALSE(u1.near_zero());

  vec3 u2 = vec3(11e-10, -1e-1, 2e-13);
  EXPECT_FALSE(u2.near_zero());

  vec3 u3 = vec3(0.5e-8, -0.05e-10, 1e-7);
  EXPECT_FALSE(u3.near_zero());
}

// Dariel
// Prueba la generacion de un vector unitario a base de un vector prefabricado
// Emmanuel, cambios menores para finalizar la pruebra de branches

TEST(Vec3Test, Unit_Vector_True) {

  vec3 u1 = vec3(1, 0, 0);
  EXPECT_TRUE(compare_vectors(unit_vector(u1), vec3(1, 0, 0)));

  vec3 u2 = vec3(0, 1, 0);
  EXPECT_TRUE(compare_vectors(unit_vector(u2), vec3(0, 1, 0)));

  vec3 u3 = vec3(0, 0, 1);
  EXPECT_TRUE(compare_vectors(unit_vector(u3), vec3(0, 0, 1)));

  vec3 u4 = vec3(2, 2, 2);
  vec3 u4_normalized = u4 / sqrt(12);
  EXPECT_TRUE(compare_vectors(unit_vector(u4), u4_normalized));

  vec3 u5 = vec3(-1, 0, 0);
  EXPECT_TRUE(compare_vectors(unit_vector(u5), vec3(-1, 0, 0)));

  vec3 u6 = vec3(0, -1, 0);
  EXPECT_TRUE(compare_vectors(unit_vector(u6), vec3(0, -1, 0)));

  vec3 u7 = vec3(0, 0, -1);
  EXPECT_TRUE(compare_vectors(unit_vector(u7), vec3(0, 0, -1)));

  vec3 u8 = vec3(-2, -2, -2);
  vec3 u8_normalized = u8 / sqrt(12);
  EXPECT_TRUE(compare_vectors(unit_vector(u8), u8_normalized));
}

// Dariel
// Prueba que no generen vectores al azar que no estan relacionados a su vector
// unitario Emmanuel, cambios menores para finalizar la pruebra de branches
TEST(Vec3Test, Unit_Vector_False) {

  vec3 u1 = vec3(1, 0, 0);
  vec3 v1 = vec3(-1, 0, 0);
  EXPECT_FALSE(compare_vectors(unit_vector(u1), v1));

  vec3 u2 = vec3(0, 1, 0);
  vec3 v2 = vec3(0, -1, 0);
  EXPECT_FALSE(compare_vectors(unit_vector(u2), v2));

  vec3 u3 = vec3(0, 0, 1);
  vec3 v3 = vec3(0, 0, -1);
  EXPECT_FALSE(compare_vectors(unit_vector(u3), v3));

  vec3 u4 = vec3(2, 2, 2);
  vec3 v4 = vec3(1, 1, 1);
  EXPECT_FALSE(compare_vectors(unit_vector(u4), v4));

  vec3 u5 = vec3(-1, 0, 0);
  vec3 v5 = vec3(1, 0, 0);
  EXPECT_FALSE(compare_vectors(unit_vector(u5), v5));

  vec3 u6 = vec3(0, -1, 0);
  vec3 v6 = vec3(0, 1, 0);
  EXPECT_FALSE(compare_vectors(unit_vector(u6), v6));

  vec3 u7 = vec3(0, 0, -1);
  vec3 v7 = vec3(0, 0, 1);
  EXPECT_FALSE(compare_vectors(unit_vector(u7), v7));

  vec3 u8 = vec3(-2, -2, -2);
  vec3 v8 = vec3(2, 2, 2);
  EXPECT_FALSE(compare_vectors(unit_vector(u8), v8));
}

// Venus
// Una prueba general de varias operaciones
TEST(Vec3Test, TotalTest) {
  vec3 u = vec3(1, 1, 2);
  vec3 v = vec3(6, 3, 1);
  vec3 w = vec3(2, 2, 3);
  vec3 z = vec3(1, 4, 0);

  vec3 suma = u + v;
  vec3 cruz = cross(w, suma);
  double punto = dot(z, cruz);
  vec3 division = u / punto;
  vec3 resultado = reflect(v, division);

  EXPECT_TRUE(compare_vectors(suma, vec3(7, 4, 3)));
  EXPECT_TRUE(compare_vectors(cruz, vec3(-6, 15, -6)));
  EXPECT_EQ(punto, 54);
  EXPECT_TRUE(compare_vectors(division, vec3(1 / 54.0, 1 / 54.0, 1 / 27.0)));
  EXPECT_TRUE(compare_vectors(resultado,
                              vec3(8737 / 1458.0, 4363 / 1458.0, 718 / 729.0)));
}

// Emmanel
// Comprobar que el vector generado está en la misma hemisferio que la normal
TEST(HemisphereTest, random_in_hemisphere_same_hemisphere) {
  vec3 normal(0.0, 1.0, 0.0); // vector normal apuntando hacia arriba
  for (int i = 0; i < 1000; ++i) {
    vec3 in_hemisphere = random_in_hemisphere(normal);

    EXPECT_GE(dot(in_hemisphere, normal), 0.0);
  }
}

// Emmanuel
// Comprobar que el vector generado está en la misma hemisferio que la normal
TEST(HemisphereTest, random_in_hemisphere_opposite_hemisphere) {
  vec3 normal(0.0, -1.0, 0.0); // vector normal apuntando hacia abajo
  for (int i = 0; i < 1000; ++i) {
    vec3 in_hemisphere = random_in_hemisphere(normal);

    EXPECT_GE(dot(in_hemisphere, normal), 0.0);
  }
}