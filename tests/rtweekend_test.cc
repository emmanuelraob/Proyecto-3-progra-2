#include <gtest/gtest.h>
#include <rtweekend.hh>
//Emmanuel 
//prueba de la funcion degrees to radians en caso de algo verdadero
TEST(rtweekend_test, degrees_to_radians_true) {
    double degrees = 180.0;
    double expected_radians = pi; 
    EXPECT_EQ(degrees_to_radians(degrees), expected_radians);
}

//Emmanuel 
//prueba de la funcion degrees to radians en caso de algo falso
TEST(rtweekend_test, degrees_to_radians_false) {
    double degrees = 90.0;
    double expected_radians = pi; 
    EXPECT_NE(degrees_to_radians(degrees), expected_radians);
}

//Emmanuel 
//prueba de la funcion random double, devuelve entre 0 y 1
TEST(rtweekend_test, random_double) {
    for(int i=0;i<100;i++){
        EXPECT_GE(random_double(),0);
        EXPECT_LE(random_double(),1);
    }
}

//Emmanuel 
//prueba de la funcion random double, devuelve varios numeros diferentes
TEST(rtweekend_test, random_double_different_numbers) {
    double first;
    double second;
    for(int i=0;i<100;i++){
        first = random_double();
        second = random_double();
        while(second==first){
            second = random_double();
        }
        EXPECT_NE(first, second);
    }
}

//Emmanuel 
//prueba de la funcion random double, devuelve entre min y max
TEST(rtweekend_test, random_double_parameters) {
    for(int i=0;i<100;i++){
        int min=i-50;
        int max=i+50;
        EXPECT_GE(random_double(min,max),min);
        EXPECT_LE(random_double(min,max),max);
    }
}

//Emmanuel 
//prueba de la funcion random double con parametros, devuelve varios numeros diferentes
TEST(rtweekend_test, random_double_parameters_different_numbers) {
    double first;
    double second;
    for(int i=0;i<100;i++){
        first = random_double(i,i+20);
        second = random_double(i,i+20);
        while(second==first){
            second = random_double(i,i+20);
        }
        EXPECT_NE(first, second);
    }
}

//Emmanuel
//prueba de la funcion clamp, x menor al minimo 
TEST(rtweekend_test,clamp_x_less){
    double x = -5.0;
    double min = 0.0;
    double max = 20.0;
    EXPECT_EQ(clamp(x,min,max),min);
}

//Emmanuel
//prueba de la funcion clamp, x mayor al maximo 
TEST(rtweekend_test,clamp_x_more){
    double x = 50.0;
    double min = 0.0;
    double max = 20.0;
    EXPECT_EQ(clamp(x,min,max),max);
}

//Emmanuel
//prueba de la funcion clamp, x entre minimo y maximo 
TEST(rtweekend_test,clamp_x_in_between){
    double x = 5.0;
    double min = 0.0;
    double max = 20.0;
    EXPECT_EQ(clamp(x,min,max),x);
}


