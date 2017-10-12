/*
 * minimumInaWindow.cpp
 *
 * Created on: 05-Oct-2017
 *      Author: sourabh
 */
#include<bits/stdc++.h>
using namespace std;
#define max 1000
int s[max];
void minWindow(int arr[],int size,int k){
	int l = 0;
	int r = 0;
	s[l] = 0;
	int j = 1;
	while(j < size){
		while(r >= l && arr[j]<arr[s[r]]){
			r--;
		}
		s[++r] = j;
		if(j >= k-1){
			cout<<arr[s[l]]<<endl;
			if(s[r]-s[l]+1>=k){
				l++;
			}
		}
		j++;
	}
}

int main(){
	int arr[] = {3,6,8,7,5,2,9,10};
	minWindow(arr,8,4);

}
