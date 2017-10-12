/*
 * binaryHeaps.cpp
 *
 *  Created on: 10-Oct-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
class minHeap{
	int *items;
	int size;
	int capacity;
public:

	minHeap(int capacity);
	int getLeftChildIndex(int parentIndex);
	int getRightChildIndex(int parentIndex);
	int getParentIndex(int childIndex);
	bool hasLeftChild(int index);
	bool hasRightChild(int index);
	bool hasParent(int index);
	int leftChild(int index);
	int rightChild(int index);
	int parent(int index);
	void swap(int index1,int index2);
	int getMin();
	int deleteMin();
	void deleteKey(int index);
	void decreaseKey(int index,int key);
	void bottomUpHeapify(int index);
	void bottomUpHeapify();
	void topDownHeapify(int index);
	void insertkey(int key);
};
// Constructor: Builds a heap from a given array a[] of given size
minHeap::minHeap(int cap)
{
	size = 0;
	capacity = cap;
	items = new int[cap];
}
int minHeap::getLeftChildIndex(int parentIndex){
	return 2*parentIndex+1;
}
int minHeap::getRightChildIndex(int parentIndex){
	return 2*parentIndex+2;
}
int minHeap::getParentIndex(int childIndex){
	return (childIndex-1)/2;
}
bool minHeap::hasLeftChild(int index){
	return (getLeftChildIndex(index)<size);
}
bool minHeap::hasRightChild(int index){
	return (getRightChildIndex(index)<size);
}
bool minHeap::hasParent(int index){
	return (getParentIndex(index)>=0);
}
int minHeap::leftChild(int index){
	return items[getLeftChildIndex(index)];
}
int minHeap::rightChild(int index){
	return items[getRightChildIndex(index)];
}
int minHeap::parent(int index){
	return items[getParentIndex(index)];
}
void minHeap::swap(int index1,int index2){
	int temp = items[index1];
	items[index1] = items[index2];
	items[index2] = temp;
}
//void minHeap::bottomUpHeapify(int index){
//	int p = getParentIndex(index);
//	while(index!=0 && items[index]<items[p]){
//		swap(index,p);
//		index = p;
//		p = getParentIndex(index);
//	}
//}
void minHeap::bottomUpHeapify(int index){
	while(hasParent(index) && parent(index)>items[index] ){
		swap(getParentIndex(index),index);
		index = getParentIndex(index);
	}
}
void minHeap::insertkey(int key){
	if(size == capacity){
		cout <<"cannot insert"<<endl;
		return;
	}

	size++;
	items[size-1] = key;
	bottomUpHeapify(size-1);
	//bottomUpHeapify(i);
}
int minHeap::getMin(){
	return items[0];
}
int minHeap::deleteMin(){

	if(size == 1){
		size--;
		return items[0];
	}
	int item = items[0];
	items[0] = items[size-1];
	size--;
	topDownHeapify(0);
	return item;
}
void minHeap::deleteKey(int index){
	decreaseKey(index,(getMin()-1));
	deleteMin();
}
void minHeap::topDownHeapify(int index){
	while(hasLeftChild(index)){
		int smallerChildIndex = getLeftChildIndex(index);
		if(hasRightChild(index) && rightChild(index) < leftChild(index)){
			smallerChildIndex = getRightChildIndex(index);
		}
		if(items[index] < items[smallerChildIndex]){
			break;
		}else{
			swap(index,smallerChildIndex);
		}
		index = smallerChildIndex;
	}
	//	int left = getLeftChildIndex(index);
	//	int right = getRightChildIndex(index);
	//	int smallest = index;
	//	if(left < size && items[left] < items[index]){
	//		smallest = left;
	//	}
	//	if(right < size && items[right] < items[smallest]){
	//		smallest = right;
	//	}
	//	if(smallest != index){
	//		swap(index,smallest);
	//		topDownHeapify(smallest);
	//	}
}
void minHeap::decreaseKey(int index,int key){
	int parent = items[index];
	items[index] = key;
	if(parent < key){
		topDownHeapify(index);
	}else{
		bottomUpHeapify(index);
	}
}

//max heap

class maxHeap{
	int *max;
	int size;
	int capacity;
public:

	maxHeap(int capacity);
	int mgetLeftChildIndex(int parentIndex);
	int mgetRightChildIndex(int parentIndex);
	int mgetParentIndex(int childIndex);
	bool mhasLeftChild(int index);
	bool mhasRightChild(int index);
	bool mhasParent(int index);
	int mleftChild(int index);
	int mrightChild(int index);
	int mparent(int index);
	void mswap(int index1,int index2);
	int mgetMax();
	int mdeleteMax();
	void mdeleteKey(int index);
	void mincreaseKey(int index,int key);
	void mbottomUpHeapify(int index);
	void mbottomUpHeapify();
	void mtopDownHeapify(int index);
	void minsertkey(int key);
};
// Constructor: Builds a heap from a given array a[] of given size
maxHeap::maxHeap(int cap)
{
	size = 0;
	capacity = cap;
	max = new int[cap];
}
int maxHeap::mgetLeftChildIndex(int parentIndex){
	return 2*parentIndex+1;
}
int maxHeap::mgetRightChildIndex(int parentIndex){
	return 2*parentIndex+2;
}
int maxHeap::mgetParentIndex(int childIndex){
	return (childIndex-1)/2;
}
bool maxHeap::mhasLeftChild(int index){
	return (mgetLeftChildIndex(index)<size);
}
bool maxHeap::mhasRightChild(int index){
	return (mgetRightChildIndex(index)<size);
}
bool maxHeap::mhasParent(int index){
	return (mgetParentIndex(index)>=0);
}
int maxHeap::mleftChild(int index){
	return max[mgetLeftChildIndex(index)];
}
int maxHeap::mrightChild(int index){
	return max[mgetRightChildIndex(index)];
}
int maxHeap::mparent(int index){
	return max[mgetParentIndex(index)];
}
void maxHeap::mswap(int index1,int index2){
	int temp = max[index1];
	max[index1] = max[index2];
	max[index2] = temp;
}
//void minHeap::bottomUpHeapify(int index){
//	int p = getParentIndex(index);
//	while(index!=0 && items[index]<items[p]){
//		swap(index,p);
//		index = p;
//		p = getParentIndex(index);
//	}
//}
void maxHeap::mbottomUpHeapify(int index){
	while(mhasParent(index) && mparent(index)<max[index] ){
		mswap(mgetParentIndex(index),index);
		index = mgetParentIndex(index);
	}
}
void maxHeap::minsertkey(int key){
	if(size == capacity){
		cout <<"cannot insert"<<endl;
		return;
	}

	size++;
	max[size-1] = key;
	mbottomUpHeapify(size-1);
	//bottomUpHeapify(i);
}
int maxHeap::mgetMax(){
	return max[0];
}
int maxHeap::mdeleteMax(){

	if(size == 1){
		size--;
		return max[0];
	}
	int item = max[0];
	max[0] = max[size-1];
	size--;
	mtopDownHeapify(0);
	return item;
}
void maxHeap::mdeleteKey(int index){
	mincreaseKey(index,(mgetMax()+1));
	mdeleteMax();
}
void maxHeap::mtopDownHeapify(int index){
	while(mhasLeftChild(index)){
		int largerChildIndex = mgetLeftChildIndex(index);
		if(mhasRightChild(index) && mrightChild(index) > mleftChild(index)){
			largerChildIndex = mgetRightChildIndex(index);
		}
		if(max[index] > max[largerChildIndex]){
			break;
		}else{
			mswap(index,largerChildIndex);
		}
		index = largerChildIndex;
	}
	//	int left = getLeftChildIndex(index);
	//	int right = getRightChildIndex(index);
	//	int smallest = index;
	//	if(left < size && items[left] < items[index]){
	//		smallest = left;
	//	}
	//	if(right < size && items[right] < items[smallest]){
	//		smallest = right;
	//	}
	//	if(smallest != index){
	//		swap(index,smallest);
	//		topDownHeapify(smallest);
	//	}
}
void maxHeap::mincreaseKey(int index,int key){
	int parent = max[index];
	max[index] = key;
	if(parent > key){
		mtopDownHeapify(index);
	}else{
		mbottomUpHeapify(index);
	}
}
int main(){
	minHeap h(11);
	h.insertkey(6);
	h.insertkey(7);
	h.insertkey(3);
	h.insertkey(1);
	cout << h.getMin()<<endl;
	cout<<h.deleteMin()<<endl;
	h.decreaseKey(2,0);
	h.deleteKey(2);
	cout << h.getMin()<<endl;
	cout<<h.deleteMin()<<endl;
	// testing maxHeap functions
	maxHeap t(10);
	t.minsertkey(6);
	t.minsertkey(7);
	t.minsertkey(3);
	t.minsertkey(1);
	cout << t.mgetMax()<<endl;
	cout<<t.mdeleteMax()<<endl;
	t.mincreaseKey(2,9);
	t.mdeleteKey(2);
	cout << t.mgetMax()<<endl;
	cout<<t.mdeleteMax()<<endl;


}



