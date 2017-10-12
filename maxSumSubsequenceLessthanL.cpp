/*
 * maxSumSubsequenceLessthanL.cpp
 *
 *  Created on: 06-Oct-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
int maxSum(int arr[],int size, int l){
	int sum = 0;
	int max = 0;
	int i = 0;
	int count = -1;
	while(i<=size){
		if(count < l){
			if(i!=size){ //to avoid garbage value addition at i = 10
			sum = sum + arr[i];
			count++;
			}
		}
		if(sum > max){
			max = sum;
		}

		if(sum < 0){
			sum = 0;
			count = -1;

		}else if(count == l-1){
			sum = 0;
			count = -1;
			i = i-l+1;
		}

		i++;
	}
	return max;
}
int main(){
	//int numElems;
	//	cout << "enter total elements" << endl;
	//cin >> numElems;
	//	int arr[numElems];
	//cout << "enter sequence" << endl;
	//for(int i = 0 ; i < numElems; i++){
	//	cin >> arr[i];
	//}
	int arr[] = {3,1,-4,200,-7,-3,2,-1,8,100};
	cout<< "enter l"<< endl;
	int l;
	cin >> l;
	int sum = maxSum(arr,10,l);
	cout << "max sum is "<< sum;

}


