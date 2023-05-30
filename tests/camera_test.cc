#include <camera.hh>
#include <gtest/gtest.h>


//Copia de la funcion get_ray de la camara, de manera que se pueda testear utilizando un random vector como parametro
ray get_ray(camera cam, double s, double t, vec3 random_in_unit_disk_muestra) {
    vec3 rd = cam.lens_radius * random_in_unit_disk_muestra;
    vec3 offset = cam.u * rd.x() + cam.v * rd.y();

    return ray(
        cam.origin + offset,
        cam.lower_left_corner + s* cam.horizontal + t* cam.vertical - cam.origin - offset
    );
}

//Dariel
//Prueba que se pueda obtener el rayo de la camara correctamente
TEST(CameraTest, Getting_Ray){
    point3 lookfrom(13,2,3);
    point3 lookat(0,0,0);
    vec3 vup(0,1,0);
    const auto aspect_ratio = 3.0 / 2.0;
    auto dist_to_focus = 10.0;
    auto aperture = 0.1;

    camera camaraPrueba = camera(lookfrom, lookat, vup, 20, aspect_ratio, aperture, dist_to_focus);

    vec3 randomVec = random_in_unit_disk();
    
    vec3 offsetEsperado = (camaraPrueba.u * randomVec.x() + camaraPrueba.v * randomVec.y()) * aperture/2;
    vec3 origenEsperado = lookfrom + offsetEsperado;
    vec3 direccionEsperada = camaraPrueba.lower_left_corner + camaraPrueba.horizontal + 2 * camaraPrueba.vertical - lookfrom - offsetEsperado;
    ray rayoEsperado = ray(origenEsperado, direccionEsperada);
    EXPECT_TRUE(compare_rays(get_ray(camaraPrueba, 1, 2, randomVec), rayoEsperado));
}