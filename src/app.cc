#include <app.hh>
#include <thread>


using namespace std;


color app::ray_color(const ray& r, const hittable& world, int depth) {
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


hittable_list app::random_scene(){
    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));
    /*
    for (int a = -7; a < 7; a++) {
        for (int b = -7; b < 7; b++) {
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
    */

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    return world;
}


void app::run(){

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

    vector<vector<vector<int>>> int_image (image_height, vector<vector<int>>(image_width,vector<int> (3,0)));

    int remaining_lines = image_height;
    mutex mtx;
    
    auto work = [=,&mtx,&remaining_lines,&int_image](int begin, int end){ 

        for (int j = begin; j < end; ++j){
            mtx.lock();
            std::cerr << "\rScanlines remaining: " << remaining_lines << ' ' << flush; 
            remaining_lines-=1;
            mtx.unlock();

            for (int i = 0; i < image_width; ++i) {
                color pixel_color(0, 0, 0);
                for (int s = 0; s < samples_per_pixel; ++s) {
                    alignas(32) double u = (i + random_double()) / (image_width-1);
                    alignas(32) double v = (j + random_double()) / (image_height-1);
                    mtx.lock();
                    ray r = cam.get_ray(u, v);
                    pixel_color += ray_color(r, world, max_depth);
                    mtx.unlock();
                }
                auto scale = 1.0 / samples_per_pixel;
                int_image[j][i][0] = static_cast<int>(256 * clamp(sqrt(scale * pixel_color[0]), 0.0, 0.999));
                int_image[j][i][1] = static_cast<int>(256 * clamp(sqrt(scale * pixel_color[1]), 0.0, 0.999));
                int_image[j][i][2] = static_cast<int>(256 * clamp(sqrt(scale * pixel_color[2]), 0.0, 0.999));
            }
        }
    };


    


    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    unsigned int n = std::thread::hardware_concurrency();
    //n=7;
    cerr << "numero de nucleos " << n << endl;
    int number_lines = (int) (image_height/n);

    vector <thread> threads;

    for (int k=0; k<n ; k++) {
        threads.push_back(thread(work,k*number_lines,(k+1)*number_lines));
        
    }
    for(auto& thread : threads) {
        thread.join();
    }
    
    for (int i = image_height-1; i >= 0; i--){
        for (int j = 0; j < image_width; j++) {
            int r = int_image[i][j][0];
            int g = int_image[i][j][1];
            int b = int_image[i][j][2];
            write_color(std::cout, r,g,b);
        }
    }
    
    std::cerr << "\nDone.\n";
    //time stop  
    auto stop = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> duration = stop - start;
    cerr << "Time taken by program: " 
            << std::fixed << std::setprecision(4) << duration.count() 
            << " seconds" << std::endl;

}


