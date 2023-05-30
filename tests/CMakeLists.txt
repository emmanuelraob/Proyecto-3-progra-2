# Quickstart CMake taken from:
# https://google.github.io/googletest/quickstart-cmake.html

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)####

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


include_directories(${GTEST_INCLUDE_DIRS})###

enable_testing()

# Se define un ejecutable de pruebas "raytracer_test",
# que requiere los siguientes archivos .cc para ser compilado.

add_executable(raytracer_test
    camera_test.cc
    ${RayTracer_SOURCE_DIR}/src/camera.cc
    color_test.cc
    ${RayTracer_SOURCE_DIR}/src/color.cc
    hittable_list_test.cc
    ${RayTracer_SOURCE_DIR}/src/hittable_list.cc
    hittable_test.cc
    ${RayTracer_SOURCE_DIR}/src/hittable.cc
    material_test.cc
    ${RayTracer_SOURCE_DIR}/src/material.cc
    ray_test.cc
    ${RayTracer_SOURCE_DIR}/src/ray.cc
    rtweekend_test.cc
    ${RayTracer_SOURCE_DIR}/src/rtweekend.cc
    sphere_test.cc
    ${RayTracer_SOURCE_DIR}/src/sphere.cc
    vec3_test.cc
    ${RayTracer_SOURCE_DIR}/src/vec3.cc
    app_test.cc
    ${RayTracer_SOURCE_DIR}/src/app.cc
)

# Además, se añaden los archivos de encabezados

target_include_directories(raytracer_test
    PUBLIC
    "${RayTracer_SOURCE_DIR}/include"
)

# Finalmente, enlazamos con la biblioteca de Google Test
target_link_libraries(raytracer_test
    GTest::gtest_main
)

target_link_libraries(raytracer_test ####
${GTEST_LIBRARIES} pthread
)

add_test(NAME raytracer_test COMMAND raytracer_test)###




include(GoogleTest)

# Añadan esto para permitir que ctest pueda descubrir las pruebas automáticamente
gtest_discover_tests(raytracer_test)


