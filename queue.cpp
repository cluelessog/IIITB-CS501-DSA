/*
 * queue.cpp
 *
 *  Created on: 09-Sep-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
#define size 1000
using namespace std;
class Queue{
	int l,r;
public :
	int arr[size];
	Queue(){
		l = -1,r=-1;
	}
	void enqueue(int x);
	void dequeue();
	bool isEmpty();

};
void Queue::enqueue(int x){
	if(l>size || r>size){
		cout <<"queue is full"<<endl;
	}else{
		arr[++r] = x;
	}
}
void Queue::dequeue(){
	if(isEmpty()){
		cout << "queue is empty"<<endl;
	}else{
		int out = arr[++l];
		cout << out << endl;
	}
}
bool Queue::isEmpty(){
	return (l==r);
}
int main(){
	struct Queue q;
	cout<< q.isEmpty()<<endl;
	q.enqueue(10);
	cout<< q.isEmpty()<<endl;
	q.enqueue(7);
	q.enqueue(5);
	q.dequeue();
	q.dequeue();
	cout<< q.isEmpty()<<endl;
	q.dequeue();
	cout<< q.isEmpty()<<endl;
}




