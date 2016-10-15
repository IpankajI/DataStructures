#include<bits/stdc++.h>			// only words of english lower case alphabates can be used
using namespace std;
struct Node{
	Node *childs[26];
	char val;
	bool leaf;
	int noOfChild;
};
class Trie{
	public:
		Node* root;
		void add(string);
		bool search(string);
		void del(string);
		Trie();
	private:
		Node* newNode(char);
		static const int N=26;
		static const char a='a';
};
Trie::Trie(){
	root=new Node;			//root node
	for(int i=N;i--;) {
		root->childs[i]=NULL;
	}
	root->val='p';
	root->leaf=true;
	root->noOfChild=0;
}
Node* Trie::newNode(char ch){
	Node* node=new Node;
	for(int i=N;i--;){
		node->childs[i]=NULL;
	}
	node->val=ch;
	node->leaf=false;
	node->noOfChild=0;
	return node;
}
void Trie::add(string str){
	Node* tmp=root;
	for(int i=0;i<str.length();i++){
		if(tmp->childs[str[i]-a]) {
			tmp=tmp->childs[str[i]-a];
		}
		else {
			tmp->noOfChild++;
			tmp->childs[str[i]-a]=newNode(str[i]);
			tmp=tmp->childs[str[i]-a];
		}
	}
	tmp->leaf=true;
}
bool Trie::search(string str){
	Node* tmp=root;
	for(int i=0;i<str.length();i++) {
		if(tmp->childs[str[i]-a]){
			tmp=tmp->childs[str[i]-a];
		}
		else return false;
	}
	return tmp->leaf;
}
void Trie::del(string str){
	int len=str.length();
	Node* index[len+10];
	Node* tmp;
	int in=0;
	index[0]=root;
	while(index[in]->childs[str[in]-a] && in<len){
		index[in+1]=index[in]->childs[str[in]-a];
		in++;
	}
	if(in==len){
		if(index[in]->noOfChild>0){
			index[in]->leaf=false;
		}
		else{
			while(index[in-1]->noOfChild==1 && index[in-1]->leaf==false){
				index[in-1]->childs[str[in-1]-a]=NULL;
				delete index[in];
				in--;
			}
		}
	}
}
int main(){
	int action,n;
	string str;
	scanf("%d",&n);
	Trie trie;
	for(int i=n;i--;){
		printf("enter 0 for deletion,1 for insertion and 2 for search\n");
		scanf("%d",&action);
		printf("enter a string\n");
		cin>>str;
		if(action==1) {
			trie.add(str);
		}
		else if(action==0) trie.del(str);
		else {
			trie.search(str)?printf("found\n"):printf("Not found\n");
		}
	}
}
