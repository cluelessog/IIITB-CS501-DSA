/*
 * insertionsort.cpp
 *
 *  Created on: 19-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
void printArr(int numArr[], int n){
	for(int i = 0 ; i < n; i++){
		cout << numArr[i] << " ";
	}
}
void insertionSort(int numArr[],int numElems){
	int key,j;
	for(int i = 1 ; i < numElems; i++){
		key = numArr[i];
		j = i-1;
		while(j > -1 && numArr[j] > key){
			numArr[j+1] = numArr[j];
			j--;
		}
	numArr[j+1] = key;
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
	insertionSort(numArr,numElems);
}

