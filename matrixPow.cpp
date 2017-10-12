/*
 * matrixPow.cpp
 *
 *  Created on: 13-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
//dynamic allocation of memory
int **createMatrix(int row,int column){
	int **mat = new int*[row];
	for(int i = 0 ; i < row ; i++){
		mat[i] = new int[column];
	}
	return mat;
}
// initialising the 2D matrix
void initializeMatrix(int **matptr,int row,int column){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			cin >> matptr[i][j] ;
		}
	}
}
//freeing the dynamically allocated memory
void freeMatrix(int **matptr, int row, int column){
	for(int i = 0 ; i < row; i++){
		delete [] matptr[i];
	}
	delete [] matptr;
}
//normal print function
void printResult(int **matptr,int row, int column){
	for(int i = 0 ; i < row; i++){
		for (int j = 0 ; j < column ; j++){
			cout << matptr[i][j] << " ";
		}
		cout << "\n" << endl;
	}
}
//subroutine to multiply two matrix
int **matrixMultiply(int **matptr1,int **matptr2,int row, int column){
	int **product;
	product = createMatrix(row,column);
	for(int i = 0; i < row; i++){
		for(int j = 0 ; j < column; j++){
			product[i][j] = 0;
			for(int k = 0; k < row; k++){
				product[i][j] = (product[i][j] + matptr1[i][k]*matptr2[k][j]);

			}
		}
	}
	return product;
}
//exponentiation function, somewhat similar to the iterative version
int **pow(int **A,int n){
	int **y;
	y = createMatrix(2,2);
	cout<< "populate identity matrix" << endl;
	initializeMatrix(y,2,2); //identity matrix
	printResult(y,2,2);
	while(n>0){
		if(n % 2 !=0){
			y = matrixMultiply(A,y,2,2);
		}
			A = matrixMultiply(A,A,2,2);
			n /= 2;
	}
	return y;
}

int main(){
	int **A,**result,n;
	cout << "enter the power" << endl;
	cin >> n ;
	A = createMatrix(2,2);
	cout << "populate the A matrix" << endl;
	initializeMatrix(A,2,2);
	printResult(A,2,2);
	result = createMatrix(2,2);
	result = pow(A,n);
	printResult(result,2,2);
	freeMatrix(result,2,2);
	freeMatrix(A,2,2);

}





