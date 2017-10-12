/*
 * maxDiff.cpp
 *
 *  Created on: 24-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;

int maxDiff(int arr[], int size){
	int min = arr[0];
	int max = arr[0];
	for(int i = 0 ; i < size; i++){
		if(min > arr[i]){
			min = arr[i];
		}
		if(max < arr[i]){
			max = arr[i];
		}
	}
	cout << "max is "<< max << endl;
	cout <<"min is "<< min << endl;
	return max-min;
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
	int dif = maxDiff(arr,size);
	cout <<"diff is "<< dif << endl;

}
