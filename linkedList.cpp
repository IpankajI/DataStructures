#include<bits/stdc++.h>
using namespace std;
struct Node{
	Node* next;
	int val;
	Node(int x){
		next=NULL;
		val=x;
	}
};
void insert(Node** root,int tmp){
	Node* node=*root;
	if(node==NULL) {
		*root=new Node(tmp);
		return;
	}
	while(node->next!=NULL) node=node->next;
	node->next=new Node(tmp);
	
}
void del(Node** root,int key){
	Node *node=*root;
	if(node==NULL) return;
	if(node->val==key){
		*root=node->next;
		delete node;
		return;
	}
	Node *p=node;
	node=node->next;
	while(node){
		if(node->val==key){
			p->next=node->next;
			delete node;
			break;
		}
		else {
			p=node;
			node=node->next;
		}
	}
}
void print(Node* root){
	while(root){
		cout<<root->val<<" ";
		root=root->next;
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"enter no number of operations ,delete +insert, to perform"<<endl;
	cin>>n;
	Node *root=NULL;
	int tmp;
	for(int i=n;i--;){
		cout<<"enter 1 for insert 0 for delete"<<endl;
		cin>>tmp;
		if(tmp==1){
			cout<<"enter no to insert"<<endl;
			cin>>tmp;
			insert(&root,tmp);
			print(root);
		}
		else if(tmp==0){
			cout<<"enter a number to delete"<<endl;
			cin>>tmp;
			del(&root,tmp);
			print(root);
		}
		else i++;
	}
}
