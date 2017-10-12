/*
 * mergeS1.cpp
 *
 *  Created on: 21-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
void printArr(int numArr[], int n){
	for(int i = 0 ; i < n; i++){
		cout << numArr[i] << " ";
	}
}
void merge(int numArr[],int start,int mid,int end){
	int B[end-start+1];
	int l = start,r = mid + 1, a = start;
		while(l <= mid && r <= end){
			if(numArr[l] <= numArr[r]){
				B[a++] = numArr[l++];
			}else{
				B[a++] = numArr[r++];
			}
		}
		while(l <= mid ){
			B[a++] = numArr[l++];
		}
		while(r <= end){
			B[a++] = numArr[r++];
		}
		a = start;
		l = start;
		while(l <= end){
			numArr[l++] = B[a++];
		}
}
void mergeSort(int A[],int start,int end){
	if(start < end){
		int mid = (start+end)/2;
		mergeSort(A,start,mid);
		mergeSort(A,mid+1,end);
		merge(A,start,mid,end);
	}
}

int main(){
	int numElems;
		cout << "enter the number of elements and sequence to be sorted" << endl;
		cin >> numElems;
		int numArr[numElems];
		for(int i = 0 ; i < numElems; i++){
			cin >> numArr[i];
		}
		int start = 0;
		int end = numElems-1;
		mergeSort(numArr,start,end);
		printArr(numArr,numElems);
}







