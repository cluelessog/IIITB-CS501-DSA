/*
 * minIndexafterNnumbers.cpp
 *
 *  Created on: 02-Oct-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
int *minIndexArray(int arr[],int inArr[]){
	stack<int> s;
	s.push(0);
	for(int j = 1 ; j < 8 ; j++){
		if(arr[j]>arr[s.top()]){
			s.push(j);
		}else{
			while((!s.empty()) && arr[j]<arr[s.top()]){
				inArr[s.top()] = j;
				s.pop();
			}
		}
		s.push(j);
	}
	return inArr;
}
int main(){
	int arr[] = {3,6,8,7,5,2,9,10};
	int inArr[] = {0,0,0,0,0,0,0,0};

	int *resArr = minIndexArray(arr,inArr);
	for(int i = 0 ; i < 8 ; i++){
		cout << resArr[i] <<" ";
	}
}



