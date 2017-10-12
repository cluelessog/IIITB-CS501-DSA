/*
 * deterministicRank.cpp
 *
 *  Created on: 03-Sep-2017
 *      Author: sourabh
 */

#include <bits/stdc++.h>
using namespace std;
void printArr(int numArr[], int start,int end){
	for(int i = start ; i < end; i++){
		cout << numArr[i] << " ";
	}
}
void bubbleSort(int arr[],int start, int end){
	for(int i = start ; i < end; i++){
		for(int j = i+1 ; j < end; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
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
int randomPartition(int arr[],int i , int j){
	srand((int)time(0));
	int rpv = i + (rand()%(j-i+1));
	int temp = arr[j];
	arr[j] = arr[rpv];
	arr[rpv] = temp;
	return partition(arr,i,j);

}
int DPartition(int arr[],int i , int j,int mpv){

	int temp = arr[j];
	arr[j] = arr[mpv];
	arr[mpv] = temp;
	return partition(arr,i,j);

}
void findRank(int arr[],int i, int j,int r){
	int k;

	if(i < j){
		k = randomPartition(arr,i,j); //returns the index of the number around which partition is to be done
		if(r == j-k+1){
			//cout << arr[k];
		}else if(r < j-k+1){
			return findRank(arr,k+1,j,r);
		}else{
			findRank(arr,i,k-1,r-(j-k+1)); //discarding numbers in right hand side will cause change in rank
		}                                  //and that change is r-(total numbers discarded);
	}
}
void DeterministicRank(int arr[], int i , int j,int r){
	if(i<j){
	int s = i,e=i+5;
	while(e <= j+1){
		bubbleSort(arr,s,e);
		s = s+5;
		e = e+5;
	}
	//sorting remaining elements when n is not a multiple of 5
	if(e > j+1){

		bubbleSort(arr,s,j+1);
	}
	cout <<"\n";
	printArr(arr,i,j+1);
	int k = i,l = k+2; //copying medians to start of array
	while(l <= j){
		int temp = arr[k];
		arr[k] = arr[l];
		arr[l] = temp;
		k++;
		l = l+5;
	}
	//cout << "\n"<< k << "\n" << i << endl;
	//cout << "\narray of medians"<<endl;
	//printArr(arr,i,k);
	//cout << "\nmedian of median is \n"<<endl;
	int median;
	if(k==1){
		median = arr[k-1];
	}else{
		DeterministicRank(arr,i,k-1,r);
	}
	cout <<median<<endl;
	//swapping median with last element for partitioning.
	int m = DPartition(arr,i,j,median);
	cout << m<<endl;
	if(r == j-m+1){
		cout << arr[m];
	}else if(r < j-m+1){
		return DeterministicRank(arr,m+1,j,r);
	}else{
		return DeterministicRank(arr,i,k-1,r-(j-k+1));
	}
	//printArr(arr,i,j+1);
    //findRank(arr,i,j,r);
	}
}

int main(){
	int numElems;
		cout << "generating sequence" << endl;
		cin >> numElems;
		int arr[numElems];
		srand((int)time(0));
		for(int i = 0; i < numElems; i++){
			arr[i] = rand()%100;   //generating a random from 0 to 9
			cout << arr[i]<< " ";
			//	cout << "total digits " << i+1 << endl;
			}
		int start = 0;
		int end = numElems-1;
		cout << "\nenter r "<< endl;
		int r;
		cin >> r;
		DeterministicRank(arr,start,end,r);
}


