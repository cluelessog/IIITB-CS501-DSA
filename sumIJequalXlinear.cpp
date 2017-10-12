/*
 * sumIJequalXlinear.cpp
 *
 *  Created on: 24-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;

bool searchX(int arr[], int x,int size,int l,int r){
	int flag = 0;
	while(l<=r){
		if(arr[l]+arr[r] == x){
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
int main(){
	int numElems;
		cout << "enter the number of elements and sorted sequence" << endl;
		cin >> numElems;
		int numArr[numElems];
		for(int i = 0 ; i < numElems; i++){
			cin >> numArr[i];
		}
		int toSearch;
		cout << "enter element to be searched" << endl;
		cin >> toSearch;
		//bool v = true;
		//cout <<"true val is " << v << endl;
		int left = 0;
		int right = numElems-1;
		bool val = searchX(numArr,toSearch,numElems,left,right);
		cout << val;
}
