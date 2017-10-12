/*
 * stackoops.cpp
 *
 *  Created on: 08-Sep-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
class Stack{

	int top;
public:
	int arr[MAX];
	Stack(){//constructor to initialise stack
		top = -1;
	}
	void push(int x);
	int pop();
	bool isEmpty();
};
void Stack::push(int x){
	if(top >= MAX){
			cout << "stack overflow"<<endl;
		}else{
			arr[++top] = x;
		}
}
int Stack::pop(){
		if(isEmpty()){
			cout <<"stack underflow"<<endl;
			return 0;
		}else{
			int to = arr[top--];
			return to;
		}
}
bool Stack::isEmpty(){
	return (top < 0);
}
int main(){
	Stack s;
	cout << s.isEmpty()<<endl;
	cout << s.pop()<<endl;
	s.push(1);
	s.push(2);
	s.push(4);
	s.push(5);
	cout <<s.pop()<<endl;
	cout <<s.pop()<<endl;
	cout << s.isEmpty()<<endl;
}


