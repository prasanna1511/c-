#include "myvector.hpp"
#include <iostream>
#include <vector>

int main(){

    Vector3d v1;
    Vector3d v2;

    v1.x = 3.23;
    v1.y = 4.566;
    v1.z = 1244.758;

    v2.x  = 4.545;
    v2.y = 5.695;
    v2.z = 56.34;

    // 1. element-wise sum of 2 vectors
    const Vector3d result =sum(v1, v2);
    std::cout << result.x <<std::endl; 
    std::cout << result.y <<std::endl;
    std::cout << result.z <<std::endl;

    // 2. scale value
    const Vector3d Result1 = scale(v1, 5);
    const Vector3d Result2 = scale(v2, 5);
    std::cout << "scale " << Result1.x <<std::endl;
    std::cout << "scale " << Result2.x <<std::endl;

    //3.  multiplication of vectors
    const Vector3d resulT = multiply(v1, v2);
    std::cout <<"mult "  << resulT.z <<std::endl;

    //  4.  norm of vectors
    double  norm_v1 = norm(v1);
    double norm_v2 = norm(v2);

    std::cout << "norm v1 " << norm_v1 << std::endl;
    std::cout << "norm_v2 " << norm_v2 << std::endl;
    
    //5.  normalization
    Vector3d normalize_v1 = normalize(v1);
    Vector3d normalize_v2 = normalize(v2);
    
    std::cout << "normalized " << normalize_v1.x <<"," << normalize_v1.y <<"," << normalize_v1.z <<std::endl;
    std::cout << "Nrmz v2 " << normalize_v2.x <<"," << normalize_v2.y <<"," << normalize_v2.z <<std::endl;

    // 6. set to constant
    setConstant( v1, 2);
    setConstant( v2, 7);

    std::cout <<" v1_const " << v1.x << v1.y << v1.z <<std::endl;
    std::cout <<" v2 " <<v2.x << v2.y << v2.z <<std::endl;

    // 7. dotproduct
    double DP = dotProduct (v1, v2);
    std::cout <<" dp " << DP <<std::endl;

    //8.  minmax
    std::tuple<double, double> min_val_v1= minmax(v1);
    std::tuple<double, double> max_val_v1 = minmax(v1);

    std::tuple<double, double> min_val_v2= minmax(v2);
    std::tuple<double, double> max_val_v2 = minmax(v2);

   

    //9.  isZeros
    bool v_1 = isZeros(v1);
    bool v_2 = isZeros(v2);
    std::cout << "bool_1    " << v_1 <<std::endl;
    std::cout << "bool_2    " << v_2 <<std::endl;


    Vector3d begin(0, 0, 0); // Example begin point
    Vector3d end(1, 1, 1);   // Example end point
   
    return 0;
}


/*void Myrandom(){
    std::vector<Vector3d> samples = ray_sampling(begin, end, 10);
    // std::vector<Vector3d>  vector_of_vector3d;
    // vector_of_vector3d.emplace_back(Vector3d{});
    for (const auto& sample : samples) {
        std::cout << sample << std::endl; // Assuming Vector3d supports output stream operator
    } 
    }*/
 