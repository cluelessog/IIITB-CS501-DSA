/*
 * minDiff.cpp
 *
 *  Created on: 24-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
void printArr(int numArr[], int n){
	for(int i = 0 ; i < n; i++){
		cout << numArr[i] << " ";
	}
}
int minDiff(int arr[], int size){
	int min = abs(arr[1]-arr[0]);
	for(int i = 2 ; i < size; i++){
		if(abs(arr[i]-arr[i-1])<min){
			min = abs(arr[i]-arr[i-1]);
		}
	}
return min;
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
	cout <<"enter size"<<endl;
	int size;
	cin >> size;
	int arr[size];
	cout << "enter the sequence" << endl;
	for(int i = 0 ; i < size ; i++){
		cin >> arr[i];
	}
	mergeSort(arr,0,size-1);
	printArr(arr,size);
	int dif = minDiff(arr,size);
	cout <<"\nmin diff is "<< dif << endl;

}




