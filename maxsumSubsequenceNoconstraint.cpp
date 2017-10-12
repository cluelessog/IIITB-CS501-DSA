/*
 * maxsumSubsequenceNoconstraint.cpp
 *
 *  Created on: 03-Sep-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
int maxSum(int arr[],int size){
	int sum = arr[0];
	int max = 0;
	int i = 1;
	while(i<size){
		if(sum<0){
			sum = 0;
		}
		sum = sum + arr[i];
		if(sum > max){
			max = sum;
		}

		i++;
	}
	return max;
}
int main(){
	int numElems;
	cout << "enter total elements" << endl;
	cin >> numElems;
	int arr[numElems];
	cout << "enter sequence" << endl;
	for(int i = 0 ; i < numElems; i++){
		cin >> arr[i];
	}

	int sum = maxSum(arr,numElems);
	cout << "max sum is "<< sum;

}




