/*
 * stacks.cpp
 *
 *  Created on: 08-Sep-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
struct Stack{
	int STACK[MAX];
	int top;
};
Stack stk;
void push(int x){
	if(stk.top >= MAX){
		cout << "stack overflow"<<endl;
	}else{
		stk.STACK[++stk.top] = x;
	}
}
int pop(){
	int to;
	if(stk.top == -1){
		cout <<"stack underflow"<<endl;
	}else{
		to = stk.STACK[stk.top--];
	}
	return to;
}
bool isEmpty(){
	return (stk.top<0);
}
int main(){
	stk.top = -1;
	push(2);
	push(3);
	push(6);
	cout << pop()<<endl;
	cout << pop()<<endl;
	cout << isEmpty()<<endl;
	cout << pop()<<endl;
	cout << isEmpty()<<endl;

}

