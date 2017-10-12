/*
 * sumIJequalKnlogn.cpp
 *
 *  Created on: 24-Aug-2017
 *      Author: sourabh
 */

#include<bits/stdc++.h>
using namespace std;
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
bool searchX(int arr[], int x,int size,int l,int r){
	int flag = 0;
	while(l<=r){
		if(arr[l]+arr[r] == x){
			cout << "num is " << arr[l] << " and " << arr[r] <<" which equals " << x <<endl;
			flag = 1;
			return true;
		}else if(arr[l] + arr[r] < x){
			l++;
		}else{
			r--;
		}
	}
	if(flag == 0){
		return false;
	}
}
bool searchK(int arr[],int size){
	bool res;
	int left = 0;
	int right = size-1;
	for(int k = 0; k < size; k++){
		int ts = arr[k];
		res = searchX(arr,ts,size,left,right);
	}
	return res;
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
	int start = 0;
	int end = size-1;
	mergeSort(arr,start,end);
	bool val = searchK(arr,size);
	cout << val << endl;

}



