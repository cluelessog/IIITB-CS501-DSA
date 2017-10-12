/*
 * selectionSort.cpp
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
void selectionSort(int numArr[],int numElems){
	int min;
	for(int i = 0 ; i < numElems - 1; i++){
		min = i;
		for(int j = i+1 ; j < numElems; j++){
			if(numArr[j] < numArr[min]){
				min = j;
			}
		}
		int temp = numArr[min];
		numArr[min] = numArr[i];
		numArr[i] = temp;
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
	selectionSort(numArr,numElems);
}



