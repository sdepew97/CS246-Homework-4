/* matrix.c

   Name:
   Resources used (websites, books other than our texts, peers):

*/

#include "matrix.h"

// checks to see if two NxM matrices are the same
bool eq_matrix(int n, int m, int mat1[n][m], int mat2[n][m])
{
  // WRITE ME
}

// prints an NxM matrix
void print_matrix(int n, int m, int mat[n][m])
{
  // WRITE ME
}

// multiplies an NxM matrix by a scalar; stores the result in `result`
void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m])
{
  // WRITE ME
}

// multiplies an N1xM1 matrix by a N2xM2 matrix, returning whether or not
// the dimensions match up. Stores the result in `result`.
bool matrix_mult(int n1, int m1, int mat1[n1][m1],
		 int n2, int m2, int mat2[n2][m2],
		 int result[n1][m2])
{
  // WRITE ME
}
