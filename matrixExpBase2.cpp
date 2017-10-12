/*
 * matrixExpBase2.cpp
 *
 *  Created on: 13-Aug-2017
 *      Author: sourabh
 */
//doing for a 1000 bit binary number
#include <bits/stdc++.h>
using namespace std;
int **createMatrix(int row,int column){
	int **mat = new int*[row];
	for(int i = 0 ; i < row ; i++){
		mat[i] = new int[column];
	}
	return mat;
}

void initializeMatrix(int **matptr,int row,int column){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			cin >> matptr[i][j] ;
		}
	}
}

void freeMatrix(int **matptr, int row, int column){
	for(int i = 0 ; i < row; i++){
		delete [] matptr[i];
	}
	delete [] matptr;
}
void printResult(int **matptr,int row, int column){
	for(int i = 0 ; i < row; i++){
		for (int j = 0 ; j < column ; j++){
			cout << matptr[i][j] << " ";
		}
		cout << "\n" << endl;
	}
}
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
int **pow(int **A,int N[],int k){
	int **y;
	y = createMatrix(2,2);
	cout<< "populate identity matrix" << endl;
	initializeMatrix(y,2,2);
	printResult(y,2,2);
	int i = 0;
	while(i<=k){
		if(N[k-1-i]==1){
			y = matrixMultiply(A,y,2,2);
		}
			A = matrixMultiply(A,A,2,2);
			i++;
	}
	return y;
}

int main(){
	int N[1000],**A,**result;
	cout << "generating random bitstream of 0's and 1's \n";
	//without srand, the sequence generated everytime was same. so used srand to generate different sequence everytime.
	srand((int)time(0));
	for(int i = 0; i < 3; i++){
		N[i] = rand()%2;   //generating a random bitstream of 0's and 1's
		cout << N[i] << endl;
	}
	A = createMatrix(2,2);
	cout << "populate the A matrix" << endl;
	initializeMatrix(A,2,2);
	printResult(A,2,2);
	result = createMatrix(2,2);
	result = pow(A,N,3);
	printResult(result,2,2);
	freeMatrix(result,2,2);
	freeMatrix(A,2,2);

}
