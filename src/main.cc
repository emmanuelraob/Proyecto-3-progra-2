#include <rtweekend.hh>
#include <color.hh>
#include <hittable_list.hh>
#include <sphere.hh>
#include <camera.hh>
#include <material.hh>

#include <iostream>
#include <chrono> 
#include <iomanip> 
#include <vector>
#include <thread>
#include <mutex>
#include <future>


using namespace std;


color ray_color(const ray& r, const hittable& world, int depth) {
    hit_record rec;

    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0)
        return color(0,0,0);

    if (world.hit(r, 0.001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth-1);
        return color(0,0,0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}


hittable_list random_scene(){
    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));
    
    /*for (int a = -3; a < 3; a++) {
        for (int b = -3; b < 3; b++) {
            auto choose_mat = random_double();
            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = color::random() * color::random();
                    sphere_material = make_shared<lambertian>(albedo);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = color::random(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);
                    world.add(make_shared<sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }
    **/

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    return world;
}


int main(){

    //time recording 
    auto start = std::chrono::high_resolution_clock::now();

    // Image

    const auto aspect_ratio = 3.0 / 2.0;
    const int image_width = 400;//400 //1200
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 50;//50 //500
    const int max_depth = 20;

    // World
    auto world = random_scene();

    // Camera
    
    point3 lookfrom(13,2,3);
    point3 lookat(0,0,0);
    vec3 vup(0,1,0);
    auto dist_to_focus = 10.0;
    auto aperture = 0.1;

    camera cam(lookfrom, lookat, vup, 20, aspect_ratio, aperture, dist_to_focus);
    
    // Render
	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";


    // Thread tools <start>
    int numThreads = std::thread::hardware_concurrency();
    //std::vector<std::thread> threads;
    std::vector<std::future<color>> futures;
    // Thread tools <end>
		
	std::cerr << "cores" << numThreads << std::endl;
	for (int j = image_height-1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {
			color pixel_color(0, 0, 0);
			int s = 0;
			while (s < samples_per_pixel) {
				int numThreadsUsed = 0;
				while (numThreadsUsed < numThreads && s < samples_per_pixel){
				
					auto u = (i + random_double()) / (image_width-1);
					auto v = (j + random_double()) / (image_height-1);
					ray r = cam.get_ray(u, v);
					futures.push_back(std::async(std::launch::async, ray_color, r, world, max_depth));
					++numThreadsUsed;
					++s;
				}
				for (auto& future : futures) {
					pixel_color += future.get();
				}
				futures.clear();
				numThreadsUsed = 0;
			}
			write_color(std::cout, pixel_color, samples_per_pixel);
		}
	}

	std::cerr << "\nDone.\n";

	//time stop  
	auto stop = std::chrono::high_resolution_clock::now(); 
	std::chrono::duration<double> duration = stop - start;
	cerr << "Time taken by program: " 
		 << std::fixed << std::setprecision(4) << duration.count() 
		 << " seconds" << std::endl;
	return 0;
}

