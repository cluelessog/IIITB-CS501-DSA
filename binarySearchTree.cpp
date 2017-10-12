/*
 * binarySearchTree.cpp
 *
 *  Created on: 07-Oct-2017
 *      Author: sourabh
 */
#include <bits/stdc++.h>
using namespace std;

struct tree{
	int data;
	struct tree *left,*right;
};
//recursive traversals;
void preorder(struct tree *root){
	if(root != NULL){
		cout << root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}


}
void inorder(struct tree *root){
	if(root != NULL){
		inorder(root->left);
		cout << root->data<<" ";
		inorder(root->right);
	}
}
void postorder(struct tree *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		cout << root->data<<" ";
	}
}
bool checkIsBST(struct tree *root,int min, int max){//linear solution, space is logn
	//base case
	if(root == NULL){
		return true;
	}
	if(root->data < min || root->data > max){
		return false;
	}
	return checkIsBST(root->left,min,root->data - 1) && checkIsBST(root->right,root->data + 1,max);
}
void Insert(struct tree **root,int info){
	tree *temp = *root; //next insertion k liye previous inserted value ko temp allocate krdo
	if(*root == NULL){
		tree *temp = new tree;
		temp->data = info;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp; //pehle insertion k baad use root bna do.
	}else{
		if(info < temp->data){
			Insert(&temp->left,info);
		}else{
			Insert(&temp->right,info);
		}
	}
}
bool searchNode(struct tree *root,int info){
	if(root == NULL){
		cout << "tree is empty"<<endl;
		return false;
	}
	if(root->data == info){
		return true;
	}
	if(info < root->data){
		if(root->left!=NULL){
			return searchNode(root->left,info);
		}
	}else{
		if(root->right!=NULL){
			return searchNode(root->right,info);
		}
	}
	return false;
}
int findMiniter(struct tree *root){
	if(root == NULL){
		cout << "Tree is empty"<<endl;
		return -1;
	}
	while(root->left!= NULL){
		root = root->left;
	}
	return root->data;
}
tree* findMinrecur(struct tree *root){
	if(root == NULL){
		cout << "Tree is empty"<<endl;
	}
	if(root->left == NULL){
		return root;
	}
	return findMinrecur(root->left);
}
int findMaxiter(struct tree *root){
	if(root == NULL){
		cout << "Tree is empty"<<endl;
		return -1;
	}
	while(root->right!= NULL){
		root = root->right;
	}
	return root->data;
}
tree* findMaxrecur(struct tree *root){
	if(root == NULL){
		cout << "Tree is empty"<<endl;
	}
	if(root->right == NULL){
		return root;
	}
	return findMaxrecur(root->right);
}
struct tree* deleteNode(struct tree *root,int data){
	//first we search for data in tree
	if(root == NULL){
		return root;
	}else if(data < root->data) root->left = deleteNode(root->left,data); //yaha 32 ka address return ho raha hai jise 44 ka left
	//child bna diya(see comment on line 127-129 and 149
	//root of left subtree i.e left child of current node
	//may change after deletion but delete returns root of modified left subtree so set return as left child of current node.

	else if(data > root->data) root->right = deleteNode(root->right,data); //same case for right one.
	else{ //data has been found
		//then deletion
		//case 0
		if(root->left == NULL && root->right == NULL){
			delete(root);
			root = NULL;
		}else if(root->left == NULL){ //case 1
			tree *temp = root; //eg 17 ka left null isliye temp mei 17
			root = root->right; //update 17 to 32 by this very given line i.e root ab 17 se 32 ho jaega
			delete(temp);
		}else if(root->right == NULL){ // case 1
			tree *temp = root;
			root = root->left;
			delete(temp);
		}else{ //case 2
			struct tree *temp = findMinrecur(root->right);
			//if(temp->data < root->data){
				root->data = temp->data;
				root->right = deleteNode(root->right,temp->data); //deleting this minimum value from right subtree
			//}else{
			//	struct tree *temp1 = findMaxrecur(root->left);
			//	root->data = temp->data;
			//	root->left = deleteNode(root->left,temp->data);

			//}

		}
	}
	return root; //modified subtree ka address i.e 32 ka address return hoga
}
int main(){
	tree *root = NULL;
	int i = 0;
	int n;
	int arr[] = {44,17,50,32,28,29,88,97,65,54,82,76,80,78,-1};
	//int arr[] = {1,2,3,4,5,6,7,8,9,10,-1};
	n = arr[i];
	while(n!=-1){
		Insert(&root,n);
		i++;
		if(arr[i]!=NULL){
			n = arr[i];
		}
	}
	preorder(root);
	cout<<"\n";
	inorder(root);
	cout<<"\n";
	postorder(root);
	cout<<"\n";
	//cout<<searchNode(root,10)<<endl;
	deleteNode(root,97);
	preorder(root);
	cout<<"\n";
	inorder(root);
	cout<<"\n";
	postorder(root);
	cout<<"\n";
	//	cout << findMiniter(root)<<endl;
	//	cout << findMinrecur(root)<<endl;
	//	cout << findMaxiter(root)<<endl;
	//	cout << findMaxrecur(root)<<endl;
	cout <<checkIsBST(root,INT_MIN,INT_MAX);


}




