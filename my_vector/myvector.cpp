#include "myvector.hpp"
#include <math.h>
#include <tuple>
#include <algorithm>


Vector3d sum(const Vector3d &lhs, const Vector3d &rhs){

    Vector3d result;
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    result.z = lhs.z + rhs.z;
    return result;
};



Vector3d scale(const Vector3d &v, double var){

    Vector3d Result;
    Result.x = v.x * var;
    Result.y = v.y * var;
    Result.z = v.z * var;
    return Result;
};


Vector3d multiply(const Vector3d &lhs, const Vector3d &rhs){
   
    Vector3d resulT;
    resulT.x = lhs.x * rhs.x;
    resulT.y = lhs.y * rhs.y;
    resulT.z = lhs.z * rhs.z;
    return resulT;
};


double norm(const Vector3d &v) {
    return std::sqrt(v.x *  v.x +  v.y *  v.y +  v.z * v.z); 
    // return std::sqrt(v2.x*v2.x + v2.y*v2.y + v2.z*v2.z);
};



Vector3d normalize(const Vector3d &v){
    double n = norm(v);
    if (n == 0);
    return v;
    return scale(v, 1.0/n);
};

void setConstant(Vector3d &v, double constant){
    
    v.x = constant;
    v.y = constant;
    v.z = constant;
   
 };

double dotProduct(const Vector3d &v1, const Vector3d &v2){
    
    return (v1.x*v2.x) +(v1.y*v2.y) +(v1.z*v2.z);
};


bool isZeros(const Vector3d &v){
    return v.x == 0 && v.y == 0 && v.z ==0;

};


std::tuple<double, double> minmax(const Vector3d &v){
    // int min =0;
    double min_val = std::min({v.x, v.y, v.z});
    double max_val = std::max({v.x, v.y, v.z});
    return std::make_tuple(min_val, max_val);
};

Vector3d minus(const Vector3d &lhs, const Vector3d &rhs){
    Vector3d result;
    result.x = lhs.x - rhs.x;
    result.y = lhs.y - rhs.y;
    result.z = lhs.z - rhs.z;
    return result;
};

Vector3d scale1(const Vector3d &v, const double scale1){
    Vector3d result;
    result.x = scale1 * v.x;
    result.y = scale1 * v.y;
    result.z = scale1* v.z;
    return result;
};


Vector3d mul(const Vector3d &lhs, const Vector3d &rhs){
     Vector3d result;
    result.x = lhs.x * rhs.x;
    result.y = lhs.y * rhs.y;
    result.z = lhs.z * rhs.z;
    return result;
}
// sample = sum(begin, scale(direction,s * magnitude))
std::vector<Vector3d> ray_sampling(const Vector3d &begin, const Vector3d &end, const int num_sample){
    
    const Vector3d diff = minus(end, begin);
    const double magnitude = norm(diff);
    const Vector3d direction = normalize(diff); // direction of ray towards end will be known
    const double step_size =1.0/ num_sample;

    std::vector<Vector3d> result;
    result.reserve(num_sample);


    Vector3d sample;
    for (double s=0; s<1.0; s+= step_size){
        sample = sum(begin , scale (direction, mul(s , magnitude)));
        result.emplace_back(sample);
    }
    return result;
};