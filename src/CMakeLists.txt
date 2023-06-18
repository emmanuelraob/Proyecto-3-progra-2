set(HEADER_LIST "${RayTracer_SOURCE_DIR}/include/*.hh")

add_executable(RayTracer
    main.cc
    rtweekend.cc
    vec3.cc
    ray.cc
    camera.cc
    color.cc
    hittable_list.cc
    hittable.cc
    material.cc
    sphere.cc
)

target_include_directories(RayTracer PUBLIC ../include)

