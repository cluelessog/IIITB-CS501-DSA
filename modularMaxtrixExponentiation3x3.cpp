/*
 * modularMaxtrixExponentiation3x3.cpp
 *
 *  Created on: 15-Aug-2017
 *      Author: sourabh
 */

#include <bits/stdc++.h>
using namespace std;
long long int **createMatrix(int row,int column){
	long long int **mat = new long long int*[row];
	for(int i = 0 ; i < row ; i++){
		mat[i] = new long long int[column];
	}
	return mat;
}

void initializeMatrix(long long int **matptr,int row,int column){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			cin >> matptr[i][j] ;
		}
	}
}

void freeMatrix(long long int **matptr, int row, int column){
	for(int i = 0 ; i < row; i++){
		delete [] matptr[i];
	}
	delete [] matptr;
}
void printResult(long long int **matptr,int row, int column){
	for(int i = 0 ; i < row; i++){
		for (int j = 0 ; j < column ; j++){
			cout << matptr[i][j] << " ";
		}
		cout << "\n" << endl;
	}
	cout << "f(n) is " << matptr[1][0] << endl;
}
long long int **matrixMultiply(long long int **matptr1,long long int **matptr2,int row, int column,int mod){
	long long int **product;
	product = createMatrix(row,column);
	for(int i = 0; i < row; i++){
		for(int j = 0 ; j < column; j++){
			product[i][j] = 0;
			for(int k = 0; k < row; k++){
				product[i][j] = (product[i][j] + matptr1[i][k]*matptr2[k][j])%mod;

			}
		}
	}
	return product;
}
long long int **powZeroToTen(long long int **A,int n,int mod){
	long long int **req;
	req = createMatrix(3,3);
	//cout<< "populate identity matrix for 0 to 10 power calculation" << endl;
	//initializeMatrix(req,2,2); //identity matrix
	req[0][0] = 1;
	req[0][1] = 0;  //100000 bar kon krega
	req[0][2] = 0;
	req[1][0] = 0;
	req[1][1] = 1;
	req[1][2] = 0;
	req[2][0] = 0;
	req[2][1] = 0;
	req[2][2] = 1;
	while(n>0){
		if(n % 2 !=0){
			req = matrixMultiply(A,req,3,3,mod);
		}
			A = matrixMultiply(A,A,3,3,mod);
			n /= 2;
	}
	return req;
}
long long int **pow(long long int **A,int N[],int k,int mod){
	long long int **y;
	y = createMatrix(3,3);
	cout<< "populate identity matrix" << endl;
	initializeMatrix(y,3,3);
	int i = 0;
	while(i<k){
		if(N[k-1-i]!=0){
			y = matrixMultiply(y,powZeroToTen(A,N[k-1-i],mod),3,3,mod); //to find y*A^Ni
		}
			A = powZeroToTen(A,10,mod); // to find A^10;
			i++;
	}
	return y;
}

int main(){
	int N[100000];
	long long int **A,**result;
	cout << "generating random sequence of 100000 digits with each digit from 0 to 9 \n";
	//without srand, the sequence generated everytime was same. so used srand to generate different sequence everytime.
	srand((int)time(0));
	for(int i = 0; i < 100000; i++){
		N[i] = rand()%10;   //generating a random from 0 to 9
		cout << N[i];
	//	cout << "total digits " << i+1 << endl;
	}
	int mod;
	cout << "\nenter the modulo value" << endl;
	cin >> mod ;
	cout << "random modulo number is "<< mod << endl;
	A = createMatrix(3,3);
	cout << "populate the A matrix" << endl;
	initializeMatrix(A,3,3);
	result = createMatrix(3,3);
	result = pow(A,N,100000,mod);
	printResult(result,3,3);
	freeMatrix(result,3,3);
	freeMatrix(A,3,3);

}



