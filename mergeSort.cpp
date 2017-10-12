/*
 * mergeSort.cpp
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
	int n1 = mid-start+1;
		int n2 = end - mid;
		int L[n1],R[n2];
		for(int i = 0 ; i < n1; i++){
			L[i] = numArr[start+i];
		}
		for(int j = 0; j < n2; j++){
			R[j] = numArr[mid+j+1];
		}
		int l=0,r=0,k=start;
		while(l < n1 && r < n2){
			if(L[l] <= R[r]){
				numArr[k++] = L[l++];
			}else{
				numArr[k++] = R[r++];
			}
		}
		while(l < n1 ){
			numArr[k++] = L[l++];
		}
		while(r < n2){
			numArr[k++] = R[r++];
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


