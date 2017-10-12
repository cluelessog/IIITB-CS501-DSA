/*
 * matrixExpBase10.cpp
 *
 *  Created on: 15-Aug-2017
 *      Author: sourabh
 */


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
				product[i][j] = (product[i][j] + matptr1[i][k]*matptr2[k][j])%100;

			}
		}
	}
	return product;
}
int **powZeroToTen(int **A,int n){
	int **req;
	req = createMatrix(2,2);
	cout<< "populate identity matrix for 0 to 10 power calculation" << endl;
	//initializeMatrix(req,2,2); //identity matrix
	req[0][0] = 1;
	req[0][1] = 0;  //1000 bar kon krega
	req[1][0] = 0;
	req[1][1] = 1;
	printResult(req,2,2);
	while(n>0){
		if(n % 2 !=0){
			req = matrixMultiply(A,req,2,2);
		}
			A = matrixMultiply(A,A,2,2);
			n /= 2;
	}
	return req;
}
int **pow(int **A,int N[],int k){
	int **y;
	y = createMatrix(2,2);
	cout<< "populate identity matrix" << endl;
	initializeMatrix(y,2,2);
	printResult(y,2,2);
	int i = 0;
	while(i<k){
		if(N[k-1-i]!=0){
			y = matrixMultiply(y,powZeroToTen(A,N[k-1-i]),2,2); //to find y*A^Ni
		}
			A = powZeroToTen(A,10); // to find A^10;
			i++;
	}
	return y;
}

int main(){
	int N[1000],**A,**result;
	cout << "generating random sequence of 1000 digits with each digit from 0 to 9 \n";
	//without srand, the sequence generated everytime was same. so used srand to generate different sequence everytime.
	srand((int)time(0));
	for(int i = 0; i < 1; i++){
		N[i] = rand()%10;   //generating a random from 0 to 9
		cout << N[i] << endl;
		cout << "total digits " << i+1 << endl;
	}
	A = createMatrix(2,2);
	cout << "populate the A matrix" << endl;
	initializeMatrix(A,2,2);
	printResult(A,2,2);
	result = createMatrix(2,2);
	result = pow(A,N,1);
	printResult(result,2,2);
	freeMatrix(result,2,2);
	freeMatrix(A,2,2);

}


