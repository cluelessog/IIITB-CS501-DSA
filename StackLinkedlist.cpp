/*
 * StackLinkedlist.cpp
 *
 *  Created on: 09-Sep-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
struct stackNode{
	int data;
	struct stackNode *next;
};

void push(struct stackNode **head,int key){
	stackNode *temp = new stackNode;
	temp->data = key;
	temp->next = *head;
	*head = temp;

}
void pop(struct stackNode **head){
	if(*head == NULL){
			cout << "stack underflow"<<endl;
		}else{
		struct stackNode *temp = new stackNode;
		temp = *head;
		*head = temp->next;
		cout << temp->data<<endl;
		delete(temp);
		}
}
bool isEmpty(struct stackNode **head){
	return (*head == NULL);
}
int main(){
	stackNode *head = NULL;
	//cout << pop(&head)<<endl;
	cout << isEmpty(&head)<<endl;
	push(&head,4);
	push(&head,6);
	push(&head,7);
	isEmpty(&head);
	pop(&head);
	cout << isEmpty(&head)<<endl;
	pop(&head);
	pop(&head);
	cout << isEmpty(&head)<<endl;

}


