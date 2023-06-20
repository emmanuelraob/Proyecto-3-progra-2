#ifndef VEC3_HH
#define VEC3_HH

#include <cmath>
#include <iostream>
#include <rtweekend.hh>
#include <immintrin.h>

using std::sqrt;

class vec3 {
    public:
        vec3() : e{0,0,0,0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2] ;
        }

        inline static vec3 random() {
            return vec3(random_double(), random_double(), random_double());
        }

        inline static vec3 random(double min, double max) {
            return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
        }

        bool near_zero() const {
            // Return true if the vector is close to zero in all dimensions.
            const auto s = 1e-8;
            return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
        }

    public:
        double e[4];
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

// vec3 Utility Functions

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}


inline vec3 operator+(const vec3 &u, const vec3 &v) {
	__m256d vec1 = _mm256_loadu_pd(u.e);
    __m256d vec2 = _mm256_loadu_pd(v.e);

    __m256d result = _mm256_add_pd(vec1, vec2);
    
    double res[4];
    _mm256_storeu_pd(res, result);

    return vec3(res[0], res[1], res[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
	__m256d vec1 = _mm256_loadu_pd(u.e);
    __m256d vec2 = _mm256_loadu_pd(v.e);

    __m256d result = _mm256_sub_pd(vec1, vec2);
    
    double res[4];
    _mm256_storeu_pd(res, result);

    return vec3(res[0], res[1], res[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
	__m256d vec1 = _mm256_loadu_pd(u.e);
    __m256d vec2 = _mm256_loadu_pd(v.e);

    __m256d result = _mm256_mul_pd(vec1, vec2);
    
    double res[4];
    _mm256_storeu_pd(res, result);

    return vec3(res[0], res[1], res[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v){
    __m256d vec1 = _mm256_loadu_pd(u.e);
    __m256d vec2 = _mm256_loadu_pd(v.e);

    __m256d result = _mm256_mul_pd(vec1, vec2);
    
    double res[4];
    _mm256_storeu_pd(res, result);

    return res[0] + res[1] + res[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    __m256d u_0 = _mm256_set1_pd(u.e[0]); 
    __m256d u_1 = _mm256_set1_pd(u.e[1]); 
    __m256d u_2 = _mm256_set1_pd(u.e[2]); 

    __m256d v_0 = _mm256_set1_pd(v.e[0]); 
    __m256d v_1 = _mm256_set1_pd(v.e[1]);
    __m256d v_2 = _mm256_set1_pd(v.e[2]);

    __m256d result_x = _mm256_sub_pd(_mm256_mul_pd(u_1, v_2), _mm256_mul_pd(u_2, v_1));
    __m256d result_y = _mm256_sub_pd(_mm256_mul_pd(u_2, v_0), _mm256_mul_pd(u_0, v_2));
    __m256d result_z = _mm256_sub_pd(_mm256_mul_pd(u_0, v_1), _mm256_mul_pd(u_1, v_0));

    __m128d result_xy = _mm256_extractf128_pd(result_x, 1);
    __m128d result_zw = _mm256_extractf128_pd(result_z, 1);
    __m128d result_yx = _mm256_castpd256_pd128(result_y);

    vec3 result;
    _mm_storeu_pd(result.e, _mm_unpacklo_pd(result_xy, result_yx));
    _mm_store_sd(&result.e[2], result_zw);

    return result;
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

vec3 random_in_unit_sphere();

vec3 random_unit_vector();

vec3 random_in_hemisphere(const vec3& normal);

vec3 reflect(const vec3& v, const vec3& n);

vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat);

vec3 random_in_unit_disk();

bool compare_vectors(vec3 u, vec3 v);

#endif
