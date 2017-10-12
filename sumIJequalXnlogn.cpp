/*
 * sumIJequalXnlogn.cpp
 *
 *  Created on: 23-Aug-2017
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
void binSearch(int A[], int N, int ts){
	int l = 0;
	int r = N-1;
	int flag = 0;
	while(l <= r){
		int mid = (l+r)/2;
		if(A[mid] == ts){
			cout <<"number found is "<< ts << endl;
			flag = 1;
			break;
		}else if(A[mid] > ts){
			r = mid-1;
		}else if(A[mid] < ts){
			l = mid+1;
		}
	}
	if(flag == 0){
		cout << "number not found" << endl ;
	}
}
void searchX(int arr[], int x,int size){
	for(int i = 0; i < size; i++){
		int arrElem = arr[i];
		cout << "checking for " << arrElem << endl;
		binSearch(arr,size,x-arrElem);
	}
}

int main(){
	int numElems;
		cout << "enter the number of elements and sequence" << endl;
		cin >> numElems;
		int numArr[numElems];
		for(int i = 0 ; i < numElems; i++){
			cin >> numArr[i];
		}
		int toSearch;
		cout << "enter element to be searched" << endl;
		cin >> toSearch;
		int start = 0;
		int end = numElems-1;
		mergeSort(numArr,start,end);
		printArr(numArr,numElems);
		searchX(numArr,toSearch,numElems);
}



