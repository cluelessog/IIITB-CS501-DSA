/*
 * quickSortnormal.cpp
 *
 *  Created on: 02-Sep-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
void printArr(int arr[], int n){
	for(int i = 0 ; i < n; i++){
		cout << arr[i] << " ";
	}
}
int partition(int arr[],int i, int j){
	int x = arr[j];
	int l = i-1;
	for(int r = i ; r < j; r++){
		if(arr[r]<=x){    //move right until you find a number less than pivot, replace it with number at index l; see cormen
			l++;
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
	}
	arr[j] = arr[l+1];
	arr[l+1] = x;
	return l+1;
}
void quickSort(int arr[],int i, int j){
	int k;
	if(i < j){
		k = partition(arr,i,j); //returns the index of the number around which partition is to be done
		quickSort(arr,i,k-1);
		quickSort(arr,k+1,j);
	}

}
int main(){
	int numElems;
		cout << "enter the number of elements and sequence to be sorted" << endl;
		cin >> numElems;
		int arr[numElems];
		for(int i = 0 ; i < numElems; i++){
			cin >> arr[i];
		}
		int start = 0;
		int end = numElems-1;
		quickSort(arr,start,end);
		printArr(arr,numElems);
}


