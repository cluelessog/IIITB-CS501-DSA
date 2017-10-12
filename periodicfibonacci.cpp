/*
 * periodicfibonacci.cpp
 *
 *  Created on: 15-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;


//function to generate random modulo number between 10 and 1000000
int calculatePeriod(int N[],int mod,int fibVal[]){
	if(mod == 1){
		return 1;
	}
	int j=2;
	int sixM[6*mod],period = 2; //array to store values till 6m as period < 6m
	sixM[0] = 0;sixM[1] = 1; // initialise above array with 0 and 1
	fibVal[0] = 0; fibVal[1] = 1; // to compute fibonacci values
	for(int i = 2 ; i < 6*mod; i++){
		sixM[i] = (sixM[i-1]+sixM[i-2])%mod;
		fibVal[j++] = sixM[i];
		if(sixM[i]==1 && sixM[i-1]==0){
			period = period -1;
			break;
		}else{
			period++;
		}
	}
	return period;
}
int modByPeriod(int N[],int period,int length){
	int n = N[0],rem;
	for(int i = 0 ; i < length ; i++){
		if(n < period){
			rem = n;   //if a number less than period is left  by else block in the end such that else block is not executed again.
						//Then n left by else block is the remainder. i.e it is not further divisible by period. check for 635%10
						//without rem = n
			if(i < length-1){
			n = n*10 + N[i+1]; //finding the decimal number from array of integers.
			}
		}else{
			rem = n%period;  //taking modulus
			if(i < length-1){
			n = rem*10 + N[i+1];  //adding remainder to next number in array
			}
		}
	}
	return rem;
}
int main(){
	int N[100000],fibVal[1000000];
	int period;
	cout << "generating random sequence of 1000 digits with each digit from 0 to 9 \n";
	//without srand, the sequence generated everytime was same. so used srand to generate different sequence everytime.
	srand((int)time(0));
	for(int i = 0; i < 100000; i++){
		N[i] = rand()%10;   //generating a random from 0 to 9
		cout << N[i];
	//	cout << "total digits " << i+1 << endl;
	}
	//int n[5] = {6,3,5};
	int mod;
	cout << "\nenter the modulo number" << endl;
	cin >> mod;
	cout << "modulo number is "<< mod << endl;
	period = calculatePeriod(N,mod,fibVal);
	cout << "Period is " << period << endl;
	int Fn;
	Fn = modByPeriod(N,period,100000);
	cout << "Location of F(n) is " << Fn << endl ;
	cout << "The value of F(n) is " << fibVal[Fn] << endl;
}



