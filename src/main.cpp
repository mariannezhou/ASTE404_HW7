#include <iostream>
#include "vec.h"

/**
 *@brief main.cpp is the main function that conducts vector operations
 *
 * It creates two 3D vectors and performs subtraction and dot product
 * operations. It then prints the results.
 *
 * @param num_args Number of command line arguments
 * @param args Command line arguments
 * @return int Exit status of program
 **/


int main(int num_args, char **args) {

 double3 a{0,1,2}; // vector 1
 double3 b{0,0,1}; // vector 2

 std::cout<<a-b<<std::endl; //!< output result of subtraction
 std::cout<<dot(a,b)<<std::endl; //!< output result of dot product

 return 0; // exit
}
