/*
 * maxSumSubSequenceexactlyL.cpp
 *
 *  Created on: 03-Sep-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
int maxSum(int arr[],int size, int l){
	int sum = 0;
	int max = 0;
	int i = 0;
	int count = 0;
	while(i<=size){
		if(count < l){
			sum = sum + arr[i];
			count++;
		}else{
			if(sum < 0){
				sum = 0;
				count = 0;
				i = i-l;
			}else{
				if(sum > max){
					max = sum;
				}
				sum = sum+arr[i]-arr[i-l];
			}
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
		cout<< "enter l"<< endl;
		int l;
		cin >> l;
		int sum = maxSum(arr,numElems,l);
		cout << "max sum is "<< sum;

}








