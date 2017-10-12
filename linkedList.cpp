/*
 * linkedList.cpp
 *
 *  Created on: 03-Sep-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
bool search(struct node *head,int x){//remove if else if causes problem
	if(head == NULL){
		cout << "list is empty"<<endl;
	}
	else{
	while(head != NULL){
		if(head->data == x){
			return true;
		}
		head = head->next;
		}
	}
	return false;
}
void addNode(struct node **head, int key){
	node *temp = new node;
	temp->data = key;
	temp->next = *head;
	*head = temp;

}
void deleteNode(struct node **head){
	if(*head == NULL){//remove star if problem occurs
		cout << "list is empty"<<endl;
	}else{
	node *temp = new node;
	temp = *head;
	*head = temp->next;
	delete(temp);
	}
}
void addatEnd(struct node **head,int key){
	node *temp = *head;
	while(temp->next != NULL){//traverse till the end--eg 6-->7->8->NULL so 8 pe ruk jao
		temp = temp->next;
	}
	node *newNode = new node;//create a new node
	newNode->data = key;//put data in new node
	temp->next = newNode;//point temp to next
	newNode->next = NULL;//point new node to null

}
void deleteatEnd(struct node **head){
	if(*head != NULL){//remove star if problem occurs
	node *temp = *head;
	node *prev;
	while(temp->next != NULL){
		prev = temp; // 6->7->8 prev stores 7
		temp = temp->next;
	}
	prev->next = NULL;
	delete(temp);
	}else{
		cout << "list is empty"<<endl;
	}

}
void addaftern(struct node **head,int key,int aftern){
	int i = 0;
	node *temp = *head;
	int pos = aftern-1;// in while loop if position is 2, pos is 1 , loop runs once i.e i=0 and if
	while(i<pos && temp != NULL){//list is 1->2->4->5 temp moves to 2 and adds number after 2 i.e between 2 and 4
		temp = temp->next;
		i++;
	}
	//node *prev = temp;
	node *nex = temp->next;
	node *newData = new node;
	newData->data = key;
	temp->next = newData;
	newData->next = nex;

}
void deleteaftern(struct node **head,int aftern){
	int i = 0;
	node *temp = *head;
	while(i < (aftern-1) && temp != NULL){
		temp = temp->next;
		cout << temp->data<<endl;
		i++;
	}
	node *prev = temp;
	node *nex = temp->next;
	prev->next = nex->next;
	delete(nex);
}
void reverseRecursive(struct node **head){
	//node *first = *head;
	//node *rest = first->next;
	node *first = NULL;
	node *rest = NULL;
	first = *head; //point take head and the recursively reverse rest of the list and last mei point head to rest
	rest = first->next;
	if(first == NULL || rest == NULL){
		return;
	}
	reverseRecursive(&rest);
	//first->next->next = first; //reverses the link at each recursive call
	//first->next = NULL;
	node *q = first->next;
	q->next = first;
	first->next = NULL;
	*head = rest;
}
void reverseIterative(struct node **head){
	node *prev = NULL,*curr = *head,*nex = NULL;
	while(curr != NULL){
		nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;
	}
	*head = prev;
}
void printList(struct node *head){
	node *temp = head; //head gets modified
	while(temp != NULL){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout <<"\n";
}
void reversePrint(struct node **head){
	node *temp = *head;
	if(temp == NULL){
		return;
	}
	reversePrint(&(temp->next));
	cout << temp->data<<"->";
}
bool hasCycle(struct node *head){
	if(head == NULL){
		return false;
	}
	node *fast = head->next;
	node *slow = head;
	while(fast != NULL && fast->next!=NULL && slow != NULL ){
		if(fast == slow){
			return true;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	return false;
	}
int main(){
	//node *head = new node; //causing extra zero to print
	node *head = NULL; //initialise head with null
	int n;
	cout << "enter first number"<<endl;
	cin >> n;
	while(n != -1){
		addNode(&head,n);
		cout << "enter next number"<<endl;
		cin >> n;
	}
	cout << "searching if an element exist in list or not"<<endl;
	bool val = search(head,6);
	cout << val << endl;
	cout << "adding at any postion"<<endl;
	cout << "enter after how many numbers"<<endl;
	int pos;
	cin >> pos;
	cout << "enter number to add"<<endl;
	int num;
	cin >> num;
	addaftern(&head,num,pos);
	printList(head);
	cout << "deleting at any postion"<<endl;
	cout << "enter after how many numbers"<<endl;
	int delpos;
	cin >> delpos;
	deleteaftern(&head,delpos);
	printList(head);
	cout << "before reversing the list"<<endl;
	printList(head);
	cout << "adding at end"<<endl;
	addatEnd(&head,9);
	printList(head);
	cout <<"printing the list in reverse order with recursion"<<endl;
	reversePrint(&head);
	reverseRecursive(&head);
	cout << "\nafter reversing the list"<<endl;
	printList(head);
	cout << "reversing iteratively(again reversed)"<<endl;
	reverseIterative(&head);
	printList(head);
	cout <<"deleting at end"<<endl;
	deleteatEnd(&head);
	printList(head);
	cout << "delete at beginning"<<endl;
	deleteNode(&head);
	printList(head);
	cout << hasCycle(head)<<endl;
}

