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
//find rank ka code
int randomPartition(int arr[],int i , int j){
	srand((int)time(0));
	int rpv = i + (rand()%(j-i+1));
	int temp = arr[j];
	arr[j] = arr[rpv];
	arr[rpv] = temp;
	return partition(arr,i,j);

}

int findRank(int arr[],int i, int j,int r){
	int k;
	int med;
	if(i < j){
		k = randomPartition(arr,i,j); //returns the index of the number around which partition is to be done
		if(r == j-k+1){
			//cout << arr[k];
			med = arr[k];
		}else if(r < j-k+1){
			return findRank(arr,k+1,j,r);
		}else{
			return findRank(arr,i,k-1,r-(j-k+1)); //discarding numbers in right hand side will cause change in rank
		}                                  //and that change is r-(total numbers discarded);
	}
	return med;
}
void DeterministicRank(int arr[], int i , int j,int r){
	int result;
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
	cout <<"sorted in group of 5\n";
	printArr(arr,i,j+1);
	int k = i,l = k+2; //copying medians to start of array
	while(l <= j){
		int temp = arr[k];
		arr[k] = arr[l];
		arr[l] = temp;
		k++;
		l = l+5;
	}
	cout <<"\nmedian array\n";
	printArr(arr,i,j+1);
	cout <<"\nindex k\n";
	cout<< k;
	cout <<"\nindex i\n";
	cout << i;
	// k is the no of elements
	int medianofmedian = findRank(arr,i,k-1,(k+1-i)/2);
	cout <<"\nmedian of median \n";
	cout << medianofmedian;
	cout <<"\nindex of median of median\n";
	//finding index of median of median
	int index;
	for(int m = i; m < j ; m++){
		if(arr[m] == medianofmedian){
			index = m;
			break;
		}
	}
	cout<<index;
	cout <<"\nprinting array after swapping\n";
	//swap with last element
	int temp = arr[j];
	arr[j] = arr[index];
	arr[index] = temp;
	printArr(arr,i,j+1);
	cout<<"\nprinting partition index\n"<<endl;
	int pindex = partition(arr,i,j);
	cout << pindex;
	cout<<"\narray after partition\n"<<endl;
	printArr(arr,i,j+1);
	if(r == j-pindex+1){
		cout <<"\n";
		cout<< arr[pindex]<<endl;
		return;
	}else if(r < j-pindex+1){
		cout <<"\n";
		result = findRank(arr,pindex+1,j,r);
		cout << result<<endl;
		return;
	}else{
		cout <<"\n";
		result = findRank(arr,i,pindex-1,r-(j-pindex+1));
		cout << result<<endl;
		return;
	}

}


int main(){
	//int numElems;
		//cout << "generating sequence" << endl;
		//cin >> numElems;
		//int arr[numElems];
		int arr[] = {1,61,47,76,59,35,24,2,51,42,44,72,90,64,31,13,74,34,88,93,99,75,51,77,62};
//		srand((int)time(0));
//		for(int i = 0; i < numElems; i++){
//			arr[i] = rand()%100;   //generating a random from 0 to 9
//			cout << arr[i]<< " ";
//			//	cout << "total digits " << i+1 << endl;
//			}
		//int start = 0;
		//int end = numElems-1;
		//int arr[] = {98 ,9, 65, 57, 12, 81, 32, 66, 41, 75};
		cout << "\nenter r "<< endl;
		int r;
		cin >> r;
		cout << "\nelement with rank r(r-1 numbers greater than that) \n"<<endl;
		 DeterministicRank(arr,0,24,r);
}


