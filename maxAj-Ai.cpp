/*
 * maxAj-Ai.cpp
 *
 *  Created on: 07-Sep-2017
 *      Author: sourabh
 *      j>i is the constraint
 */
#include <bits/stdc++.h>
using namespace std;
int maxjgreateri(int *arr,int size){
	int i = 0,j=1;
	int max = *(arr + j)-*(arr + i); //*(arr + j)-*(arr + i) this way we are dereferencing the value stored at address arr+j and arr+i
									//as arr itself is the address
	j++;
	while(j<size){
		if(*(arr+i) > *(arr+j-1)){
			i = j-1;//updating minimum index
		}
		if(*(arr+j)-*(arr+i) > max){
			max = *(arr+j)-*(arr+i);
		}
		j++;
	}
	return max;
}
int main(){
	int numElems;
		cout << "enter total elements" << endl;
		cin >> numElems;
		int *arr = new int[numElems]; //dynamic allocation in c++;
		cout << "enter sequence" << endl;
		for(int i = 0 ; i < numElems; i++){
			cin >> arr[i];
		}
		int result = maxjgreateri(&arr[0],numElems); //passing address of first element in array
		cout <<"max is "<<result;
}



