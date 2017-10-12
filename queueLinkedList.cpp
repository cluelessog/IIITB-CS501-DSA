/*
 * queueLinkedList.cpp
 *
 *  Created on: 09-Sep-2017
 *      Author: sourabh
 *      queue using linked list, deletion at begginning and addition at end
 */
#include <bits/stdc++.h>
using namespace std;
struct queueNode{
	int data;
	struct queueNode *next;
};
bool isEmpty(struct queueNode **head){
	return (*head ==  NULL);
}
void enqueue(struct queueNode **head,int key){
	queueNode *temp = new queueNode;
	queueNode *tem;
	if(*head == NULL){
		temp->data = key;
		temp->next =  *head;
		*head = temp;
	}else{
		tem = *head;
	while(tem->next != NULL){

		tem = tem->next;
	}
	queueNode *newNode = new queueNode;
	newNode->data = key;
	tem->next = newNode;
	newNode->next = NULL;
	}

}
int dequeue(struct queueNode **head){
	queueNode *temp = NULL;
	int store = 0;
	if(*head == NULL){
		cout << "queue is empty"<<endl;
	}else{
		temp = *head;
		*head = temp->next;
		store = temp->data;
		delete(temp);
	}
	return store;
}
int main(){
	queueNode *head = NULL;
	cout << isEmpty(&head)<<endl;
	cout << dequeue(&head)<<endl;
	enqueue(&head,5);
	cout << isEmpty(&head)<<endl;
	enqueue(&head,6);
	enqueue(&head,9);
	cout << dequeue(&head)<<endl;
	cout << dequeue(&head)<<endl;
	cout << dequeue(&head)<<endl;
	cout << isEmpty(&head)<<endl;


}



