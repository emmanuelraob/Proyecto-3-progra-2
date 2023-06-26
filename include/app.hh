#ifndef APP_HH
#define APP_HH


#include <rtweekend.hh>
#include <color.hh>
#include <hittable_list.hh>
#include <sphere.hh>
#include <camera.hh>
#include <material.hh>

#include <iostream>
#include <chrono> //estas dos se usan para saber el tiempo 
#include <iomanip> // que dura en ejecutarse el programa

using namespace std;

class app{
	
	public:
		color ray_color(const ray& r, hittable& world, int depth);
		hittable_list random_scene();
		void run(); 
};

#endif
