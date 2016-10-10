#include<bits/stdc++.h>
using namespace std;
struct Node{
	int key;
	Node *right;
	Node *left;
};
void add(int x,Node** head){
	if(*head==NULL){
		Node *new_node=new Node;
		new_node->key=x;
		new_node->left=NULL;
		new_node->right=NULL;
		*head=new_node;
	}
	else if(x>(*head)->key) add(x,&((*head)->right));
	else add(x,&((*head)->left));
}
void inorder(Node* head){
	if(head==NULL) return;
	inorder(head->left);
	cout<<head->key<<" ";
	inorder(head->right);
}
bool same_BT(Node* head1,Node *head2){
	if(head1==NULL && head2==NULL) return true;
	else if(head1==NULL || head2==NULL) return false;
	else return head1->key==head2->key && same_BT(head1->left,head2->left) && same_BT(head1->right,head2->right);
}
int size_BT(Node *head){
	if(head==NULL) return 0;
	else return 1+size_BT(head->left)+size_BT(head->right);
}
int max_height(Node* head){
	if(head==NULL) return 0;
	else return max(max_height(head->left),max_height(head->right))+1;
}
int min_height(Node* head){
	if(head==NULL) return 0;
	else return min(min_height(head->left),min_height(head->right))+1;
}
int lca(int a,int b,Node* head){ //for BST
	if(head==NULL) return -1;
	else if(a<head->key && b>head->key) return head->key;
	else if(head->key>a && head->key>b) return lca(a,b,head->left);
	else return lca(a,b,head->right);
}
int inorderSuccessor(Node* node){
	while(node->left!=NULL) node=node->left;
	return node->key;
}
Node* deleteNode(Node* node,int x){
	if(node==NULL) return node;
	else if(node->key>x){
		node->left=deleteNode(node->left,x);
	} 
	else if(node->key<x){
		node->right=deleteNode(node->right,x);
	}
	else{
		if(node->left==NULL){
			Node* x=node->right;
			delete node;
			return x;
		}
		else if(node->right==NULL){
			Node* x=node->left;
			delete node;
			return x;
		}
		else{
			int s=inorderSuccessor(node->right);
			node->key=s;
			node->right=deleteNode(node->right,s);
		}
	}
	return node;
}
int main(){
	Node *head1=NULL,*head2=NULL,*node=NULL;
	int x,key,n;
	printf("Enter number of action to be performed\n");
	cin>>n;
	while(n--){
		printf("Enter 1 to add element 0 to delete the  key\n");
		cin>>x>>key;
		if(x==1) {
			add(key,&node);
		}
		else node=deleteNode(node,key);
		printf("inorder traversal\n");
			inorder(node);
			printf("\n");
	}
}
