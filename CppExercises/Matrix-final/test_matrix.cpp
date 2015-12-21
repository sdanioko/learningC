/* This file aims at testing all the functions we have defined in matrix.h and defined in matrix.cpp.
 * Also, it contains the answer of task 5 of lecture 11
*/


#include <iostream>
#include "matrix.h"
#include <sstream>
int main() {
  // Define two 10x10 matrices with element types of long double
  // The first has all elements set to 1.0
  // The second has all elements set to 2.0
  Matrix<long double> mat1(10, 10, 1.0);
  Matrix<long double> mat2(10, 10, 2.0);

  // Set a few elements differently as a test of accessors
  mat1(3,4) = 10.0;
  mat2(1,2) = -15.0;

  // Define a third matrix as the sum of the first two
  Matrix<long double> mat3 = mat1 + mat2;

  // Print out the third matrix as a text array
  std::cout << " The result of the matrix addition obatained from the original code is : " << std::endl;
  std::cout << std::endl;
  for (int i=0; i<mat3.get_rows(); i++) {
    for (int j=0; j<mat3.get_cols(); j++) {
      std::cout << mat3(i,j) << ", ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  std::cout << " Let's make sure about the validity of our printme function for let's print mat3" << std:: endl;
  std::cout << std::endl;
  mat3.printme();
  std::cout << std::endl;
  
  // Define a third matrix as the product of the first two
  Matrix<long double> mat4 = mat1*mat2;
  std::cout<< std::endl;
  // Print out the third matrix as the product of the second two
  std::cout << " The result of the matrix multiplication  obatained from the original code is : " << std::endl;
  std::cout << std::endl;
  for (int i =0; i<mat4.get_rows(); i++) {
    for ( int j =0; j<mat4.get_cols(); j++) {
      std::cout << mat4(i,j) << " ,";
    }
    std::cout << std::endl;
}
  std::cout << std::endl;
  std::cout << " let's make sure about the validity of our matrix multiplication function " << std:: endl;
  std::cout<< std::endl;
  mat4.printme(); 
  std::cout <<std::endl;
  
  //  The  element by element matrix addition is 
  Matrix<long double > mat5 = mat1.add_mat_elmt_by_elmt(mat1);
  std::cout << " The result of the matrix addition element by element is : " << std::endl;
  std::cout << std::endl;
  mat5.printme(); 
  std::cout << std::endl;

 // test of adding a scalar to each entry of a matrix
  Matrix<long double> mat6 = mat1*(3);
  std::cout << " The result of the addition of an integer to each entry of the matrix is : " << std::endl;
  std::cout << std::endl;
  mat6.printme();
  std::cout << std::endl;

 // test of the substraction of matrices
  Matrix<long double> mat7 = mat1 - mat2;
 // print out the third matrix as a text array
  std::cout << " The result of the substraction of two matrices is : " << std::endl;
  std::cout << std::endl;
  mat7.printme();
 
 // Let's test whether or not our save function is well operating
  char* filename = (char*)"Justin.csv";
  mat7.save(filename); // for the sake of simplicity, let's just test it with math7. However, one could have just apply this function 
  // to each of the matrix we have obtained above. 
  return 0;
}
