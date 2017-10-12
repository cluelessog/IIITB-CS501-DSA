/*
 * bubbleSort.cpp
 *
 *  Created on: 20-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
void printArr(int numArr[], int n){
	for(int i = 0 ; i < n; i++){
		cout << numArr[i] << " ";
	}
}
void bubbleSort(int numArr[],int numElems){
	for(int i = 0 ; i < numElems - 1; i++){
		for(int j = i+1 ; j < numElems; j++){
			if(numArr[i] > numArr[j]){
				int temp = numArr[i];
				numArr[i] = numArr[j];
				numArr[j] = temp;
			}
		}
	}
	printArr(numArr,numElems);
}

int main(){

	int numElems;
	cout << "enter the number of elements and sequence to be sorted" << endl;
	cin >> numElems;
	int numArr[numElems];
	for(int i = 0 ; i < numElems; i++){
		cin >> numArr[i];
	}
	bubbleSort(numArr,numElems);
}



