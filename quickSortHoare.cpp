/*
 * quickSortHoare.cpp
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
int partition(int arr[],int i, int j,int p){
	int l = i,r = j;
	while(l < r){

		while(arr[l] <= p){
			l++;
		}

		while(arr[r] >= p){
			r--;
		}

		if(l<r){
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}else{
			return l;
		}
	}
}
int rPivot(int arr[],int i , int j){
	srand((int)time(0));
	int rpv = arr[i + (rand()%(j-i+1))];
	cout << "\nrpv "<<rpv <<"\n";
	return rpv;

}
void quickSort(int arr[],int i, int j){
	int p,k;
	if(i < j){
		p = rPivot(arr,i,j);  //choose random pivot
		k = partition(arr,i,j,p); //partitions array around pivot and return final index of chosen pivot as pivot is random
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




