#ifndef COLOR_HH
#define COLOR_HH

#include <iostream>
#include <vec3.hh>
#include <immintrin.h>

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel);
void write_color(std::ostream &out,int r, int g, int b);
#endif
