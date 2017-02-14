/* matrix.c

   Name: Sarah Depew
   Resources used (websites, books other than our texts, peers, TA): TA, https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm, http://matrix.reshish.com/multiplication.php, http://matrix.reshish.com/power.php

*/

#include "matrix.h"

// checks to see if two NxM matrices are the same
bool eq_matrix(int n, int m, int mat1[n][m], int mat2[n][m]){
	//nested for loops that check if each value in each location is the same
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat1[i][j]!=mat2[i][j]){
				//if the comparison fails, then return false
				return false; 
			}
		}
	}
	
	//finishes loops and has not returned false or none of the tests failed, then it should return true
	return true;
}

// prints an NxM matrix
void print_matrix(int n, int m, int mat[n][m]){
	//nested for loops that print the matrices 
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			//formats the printed values
			printf("%4.d", mat[i][j]);
		}
		//prints a new line to separate rows onto a new line
		printf("\n"); 
	}
}

// fills in an NxN matrix with the identity matrix
void identity_mat(int n, int mat[n][n]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			//if i and j are equal, then the value is 1
			if(i==j){
				mat[i][j] = 1; 
			}
			//otherwise just put a zero
			else{
				mat[i][j] = 0; 
			}
		} 
	}
}

// multiplies an NxM matrix by a scalar; stores the result in `result`
void scalar_mult(int scalar, int n, int m, int mat[n][m], int result[n][m]){
	//nested for loop that accesses each value of the 2-dimensional array
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			//multiplies the value of the input matrix by the scalar and stores the result in the well-named result matrix
			result[i][j] = mat[i][j]*scalar;
		}
	}
}

// multiplies an N1xM1 matrix by a M1xM2 matrix, storing the result in `result`
void matrix_mult(int n1, int m1, int mat1[n1][m1], int m2, int mat2[m1][m2], int result[n1][m2]){
	
	//value to hold the result of the matrix multiplication and the value that is inserted into the result matrix
	int result_multi = 0;  
	
	//tripple nested for loop that does the multiplication 
	for(int i=0; i<m2; i++){
		for(int j=0; j<n1; j++){
			for(int k=0; k<m1; k++){
				//result accumulates in result
				result_multi+=(mat1[j][k]*mat2[k][i]);
			}
			
		//assigns the result to the proper location in the result matrix
		result[j][i] = result_multi; 
		
		//resets the result value each time
		result_multi = 0; 
		}
	}              
}

// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow(int n, int mat[n][n], int power,
                int result[n][n]){
 	
 	//a temporary matrix that will be used to multiply the result by each time
 	int temp[n][n];
 	
 	//temp now has value of mat
 	scalar_mult(1, n, n, mat, temp); 
 	
 	//matrix is raised to zero you get the identity matrix
 	if(power==0){
 		//simply fills result with the identity matrix
 		identity_mat(n, result); 
 	}
 	
 	//matrix is raised to one
 	else if(power==1){
 		//puts a matrix that is multiplied by one/the mat parameter into result
 		scalar_mult(power, n, n, mat, result); 
 	}
 	
 	//matrix is raised to power that is positive 
 	else if(power>1){
 		//matrix_mult(n, n, temp, n, mat, result); 
 		//matrix_pow(n, mat, power-1, result); 
 	
 		//repeats the matrix multiplication the proper number of times
 		while(power>1){
 			matrix_mult(n, n, temp, n, mat, result); 
 			scalar_mult(1, n, n, result, temp);
 			power--; 
 		}
 	}
 	//matrix is raised to an invalid value, so an error message prints out
 	else{
 		printf("I am sorry, the matrix power %d is invalid. Matrix powers must be non-negative.\n", power); 
 	}    
}

// Exponentiate an NxN matrix. The result is stored in `result`.
void matrix_pow_rec(int n, int mat[n][n], int power, int result[n][n]){
	int temp[n][n];
 	
 	//temp now has value of mat
 	scalar_mult(1, n, n, mat, temp);
 
 	//base case is the identity matrix
	if(power==0){
 		identity_mat(n, result); 
 	}
 	
 	//to a power of one is simply mat that was an argument passed into the function as a parameter 
 	else if(power==1){
 		scalar_mult(power, n, n, mat, result);
 	}
 	
 	//the recursive portion that completes the power function according to cases
 	else if(power>1){
 		matrix_mult(n, n, mat, n, mat, temp);
 		
 		if(power%2==0){
 			matrix_pow_rec(n, temp, power/2, result);
 		}
 		
 		else{
 			matrix_pow_rec(n, temp, (power-1)/2, result);
 		}
 	}
}

//Fills the nxn matrix with random values between 0-99
void fill_matrix(int n, int mat[n][n]){
	for(int i=0; i<n; i++){
  		for(int j=0; j<n; j++){
  			mat[i][j] = rand()%100; 
  		}
  	}
}


