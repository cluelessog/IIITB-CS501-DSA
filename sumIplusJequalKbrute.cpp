/*
 * sumIplusJequalK.cpp
 *
 *  Created on: 24-Aug-2017
 *      Author: sourabh
 */
#include<bits/stdc++.h>
using namespace std;
bool bruteForce(int arr[], int size){
	for(int i = 0; i < size; i++){
		for(int j = i+1 ; j < size ; j++){
			for(int k = 0; k < size; k++){
				if(arr[i] + arr[j] == arr[k]){
					cout << "num is " << arr[i] << " and " << arr[j] <<" which equals " << arr[k] <<endl;
					return true;
				}
			}
		}
	}
	return false;
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
	bool res = bruteForce(arr,size);
	cout << res << endl;

}



