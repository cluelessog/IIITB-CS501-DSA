//this problem is same as finding the r'th smallest number is an unsorted list
#include <bits/stdc++.h>
using namespace std;
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
	return l+1;//39 42 21 67 57 38 76 71
}
int randomPartition(int arr[],int i , int j){
	srand((int)time(0));
	int rpv = i + (rand()%(j-i+1));
	int temp = arr[j];
	arr[j] = arr[rpv];
	arr[rpv] = temp;
	return partition(arr,i,j);

}
void findRank(int arr[],int i, int j,int r){
	int k;
	if(i < j){
		k = randomPartition(arr,i,j); //returns the index of the number around which partition is to be done
		if(r == j-k+1){
			cout << "the number with rank r is  " << arr[k]<< endl;
		}else if(r < j-k+1){
			findRank(arr,k+1,j,r);
		}else{
			findRank(arr,i,k-1,r-(j-k+1)); //discarding numbers in right hand side will cause change in rank
		}                                  //and that change is r-(total numbers discarded);
	}

}
int main(){
	int numElems;
		cout << "enter a distinct sequence" << endl;
		cin >> numElems;
		int arr[numElems];
		for(int i = 0 ; i < numElems; i++){
			cin >> arr[i];
		}
		int start = 0;
		int end = numElems-1;
		cout << "enter r "<< endl;
		int r;
		cin >> r;
		findRank(arr,start,end,r);
}



