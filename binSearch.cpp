/*
 * binSearch.cpp
 *
 *  Created on: 21-Aug-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
void binSearch(int A[], int N, int ts){
	int l = 0;
	int r = N-1;
	int flag = 0;
	while(l <= r){
		int mid = (l+r)/2;
		if(A[mid] == ts){
			cout <<"number found"<<endl;
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
int main(){

	int numElems;
	cout << "enter sorted sequence" << endl;
	cin >> numElems;
	int numArr[numElems];
	for(int i = 0 ; i < numElems; i++){
		cin >> numArr[i];
	}
	cout << "Enter the number to be searched" << endl;
	int toSearch;
	cin >> toSearch;
	binSearch(numArr,numElems,toSearch);
}



