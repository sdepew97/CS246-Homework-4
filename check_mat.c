/* check_mat.c

   Name: Sarah Depew

   Unit tests for the matrix functions.

*/

#include <stdbool.h>
#include <check.h>
#include "matrix.h"

//test for matrix equality 
START_TEST(test_eq_matrix){

  //matrices to check
  int mat1[2][3] = {{1, 2, 3},{4, 5, 6}};
  int mat2[2][3] = {{7, 8, 9},{10, 11, 12}};
  int mat3[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
  int mat4[2][3] = {{1, 2, 3},{7, 8, 9}};
  int mat5[3][3] = {{1, 5, 3},{4, 5, 6},{7, 8, 9}};
  
  ck_assert(eq_matrix(2, 3, mat1, mat1));
  ck_assert(eq_matrix(2, 3, mat2, mat2));
  ck_assert(eq_matrix(3, 3, mat3, mat3));
  ck_assert(eq_matrix(2, 3, mat4, mat4));
  
  ck_assert(!eq_matrix(2, 3, mat1, mat2));
  ck_assert(!eq_matrix(2, 3, mat1, mat4));
  ck_assert(!eq_matrix(3, 3, mat3, mat5));
}
END_TEST

//test for the identity matrix
START_TEST(test_identity_mat){

  //Identity matrices 
  int ident_1[1][1] = {{1}};
  int ident_2[2][2] = {{1, 0},{0, 1}};
  int ident_3[3][3] = {{1, 0, 0},{0, 1, 0},{0, 0, 1}};
  int ident_4[4][4] = {{1, 0, 0, 0},{0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  
  //result matrices 
  int result_1[2][2];
  int result_2[2][2];
  int result_3[3][3];
  int result_4[4][4];
  
  identity_mat(1, result_1);
  identity_mat(2, result_2);
  identity_mat(3, result_3);
  identity_mat(4, result_4);

  ck_assert(eq_matrix(1, 1, ident_1, result_1));
  ck_assert(eq_matrix(2, 2, ident_2, result_2));
  ck_assert(eq_matrix(3, 3, ident_3, result_3));
  ck_assert(eq_matrix(4, 4, ident_4, result_4));
}
END_TEST

//test for scalar multiplication 
START_TEST(test_scalar_mult){
 
  //scalar values
  int scalar_1 = 1; 
  int scalar_2 = 2; 
  int scalar_3 = 3; 
  int scalar_4 = 4; 
  
  //Matrix to multiply
  int matrix[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}; 

  //matrices to compare based on scalar value
  int matrix_1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}; 
  int matrix_2[3][4] = {{2, 4, 6, 8}, {10, 12, 14, 16}, {18, 20, 22, 24}}; 
  int matrix_3[3][4] = {{3, 6, 9, 12}, {15, 18, 21, 24}, {27, 30, 33, 36}}; 
  int matrix_4[3][4] = {{4, 8, 12, 16}, {20, 24, 28, 32}, {36, 40, 44, 48}}; 
  
  //result matrices named based on value of scalar
  int result_1[3][4];
  int result_2[3][4];
  int result_3[3][4];
  int result_4[3][4];
  
  scalar_mult(scalar_1, 3, 4, matrix, result_1);
  scalar_mult(scalar_2, 3, 4, matrix, result_2); 
  scalar_mult(scalar_3, 3, 4, matrix, result_3); 
  scalar_mult(scalar_4, 3, 4, matrix, result_4);

  ck_assert(eq_matrix(3, 4, matrix_1, result_1));
  ck_assert(eq_matrix(3, 4, matrix_2, result_2));
  ck_assert(eq_matrix(3, 4, matrix_3, result_3));
  ck_assert(eq_matrix(3, 4, matrix_4, result_4));
}
END_TEST

//test for matrix multiplication 
START_TEST(test_matrix_mult){
	
	//matrices with _name of test
	int mat1_1[2][2] = {{1, 2}, {3, 4}}; 
	int mat1_2[5][2] = {{5, 2}, {16, 4}, {12, 6}, {18, 1}, {10, 2}}; 
	int mat1_3[2][2] = {{1, 2}, {3, 4}}; 
	
	int mat2_1[2][3] = {{5, 6, 7}, {8, 9, 10}}; 
	int mat2_2[2][2] = {{1, 2},{3, 4}}; 
	int mat2_3[2][3] = {{8, 6, 7}, {9, 9, 10}}; 
	
	int expected_1[2][3] = {{21, 24, 27}, {47, 54, 61}}; 
	int expected_2[5][2] = {{11, 18}, {28, 48}, {30, 48}, {21, 40}, {16, 28}}; 
	int expected_3[2][3] = {{26, 24, 27}, {60, 54, 61}};
	
	//result matrices to store the result of each test
	int result_1[2][3]; 
	int result_2[5][2]; 
	int result_3[2][3]; 
	
	matrix_mult(2, 2, mat1_1, 3, mat2_1, result_1); 
	matrix_mult(5, 2, mat1_2, 2, mat2_2, result_2);
	matrix_mult(2, 2, mat1_3, 3, mat2_3, result_3); 
	
	ck_assert(eq_matrix(2, 3, expected_1, result_1));
	ck_assert(eq_matrix(2, 3, expected_2, result_2));
	ck_assert(eq_matrix(2, 3, expected_3, result_3));
	ck_assert(!eq_matrix(2, 3, result_3, result_1));
} 
END_TEST

//check for slow exponentiation
START_TEST(test_matrix_pow){

  //matrices to raise to a power with a _number of test
  int matrix_1[2][2] = {{1, 2}, {3, 4}};
  int matrix_2[3][3] = {{1, 4, 5}, {2, 33, 9}, {3, 3, 5}}; 
  
  //result matrices 
  int result_1[2][2]; 
  int result_2[3][3]; 
  int result_3[3][3]; 
  
  //expected results
  int expected_1[2][2] = {{7, 10}, {15, 22}}; 
  int expected_2[3][3] = {{524, 5277, 1809}, {3399, 38528, 12351}, {477, 4455, 1589}}; 
  int expected_3[3][3] = {{24, 151, 66}, {95, 1124, 352}, {24, 126, 67}}; 
  
  matrix_pow(2, matrix_1, 2, result_1); 
  matrix_pow(3, matrix_2, 3, result_2); 
  matrix_pow(3, matrix_2, 2, result_3); 

  ck_assert(eq_matrix(2, 2, expected_1, result_1));
  ck_assert(eq_matrix(3, 3, expected_2, result_2));
  ck_assert(eq_matrix(3, 3, expected_3, result_3));
  ck_assert(!eq_matrix(3, 3, result_3, result_2));
}
END_TEST 

//check for fast exponentiation
START_TEST(test_matrix_pow_rec){
 
  //randomly generated matrices with _test name and fills these matrices with values that are randomly generated and kept between 0 and 99
  int matrix_1[2][2]; 
  fill_matrix(2, matrix_1); 
  
  int matrix_2[3][3];
  fill_matrix(3, matrix_2);
  
  int matrix_3[4][4];
  fill_matrix(4, matrix_3); 
  
  int matrix_4[4][4];
  fill_matrix(4, matrix_4); 
  
  //results of the exponentiation   
  int result_1_slow[2][2]; 
  int result_1_fast[2][2]; 
  
  int result_2_slow[3][3]; 
  int result_2_fast[3][3]; 
  
  int result_3_slow[4][4]; 
  int result_3_fast[4][4]; 
  
  int result_4_slow[4][4]; 
  int result_4_fast[4][4]; 
  
  
  matrix_pow(2, matrix_1, 2, result_1_slow); 
  matrix_pow_rec(2, matrix_1, 2, result_1_fast);
  
  matrix_pow(3, matrix_2, 2, result_2_slow); 
  matrix_pow_rec(3, matrix_2, 2, result_2_fast);
    
  matrix_pow(4, matrix_3, 2, result_3_slow); 
  matrix_pow_rec(4, matrix_3, 2, result_3_fast);
  
  matrix_pow(4, matrix_4, 2, result_4_slow); 
  matrix_pow_rec(4, matrix_4, 2, result_4_fast);
  
  ck_assert(eq_matrix(2, 2, result_1_slow, result_1_fast));
  ck_assert(eq_matrix(3, 3, result_2_slow, result_2_fast));
  ck_assert(eq_matrix(4, 4, result_3_slow, result_3_fast));
  ck_assert(!eq_matrix(4, 4, result_4_slow, result_3_fast));
}   
END_TEST

// the main() function for unit testing is fairly prescribed.
int main(){
  // `check` allows for multiple test suites, but we'll always
  // just have one, called "main"
  Suite* s = suite_create("main");

  // Inside a suite are potentially many `TCase`s.
  TCase* tc = tcase_create("matrix");

  // Each TCase can have many individual testing functions.
  tcase_add_test(tc, test_eq_matrix);
  tcase_add_test(tc, test_identity_mat);
  tcase_add_test(tc, test_scalar_mult);
  tcase_add_test(tc, test_matrix_mult);
  tcase_add_test(tc, test_matrix_pow);
  tcase_add_test(tc, test_matrix_pow_rec);

  // Having set up the TCase, add it to the suite:
  suite_add_tcase(s, tc);

  // To run the tests, we need a runner:
  SRunner* sr = srunner_create(s);

  // You can see options for running only some of the tests at
  // the documentation link above. The CK_NORMAL indicates to
  // print only failing tests.
  srunner_run_all(sr, CK_NORMAL);

  // after running, we can retrieve the number of failures
  int number_failed = srunner_ntests_failed(sr);

  // We're done now with the testsuite, so dispose of it properly
  srunner_free(sr);

  // conveniently, number_failed makes a nice exit code.
  // a non-zero answer means a failed test!
  return number_failed;
}
				    
