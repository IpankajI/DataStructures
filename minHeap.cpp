#include<bits/stdc++.h>
using namespace std;
const int N=1e5,INF=1e9;
int index=0,heap[N];
void init(){
	for(int i=0;i<N;i++) heap[i]=INF;
}
void insertHeapify(int in){
	int x=in>>1;
	int y=in^1;
	bool f=false;
	if(x==0) return;
	if(heap[x]>heap[in]){
		int tmp=heap[x];
		heap[x]=heap[in];
		heap[in]=tmp;
		f=true;
	}
	if(heap[x]>heap[y]){
		int tmp=heap[x];
		heap[x]=heap[y];
		heap[y]=tmp;
		f=true;
	}
	if(f) insertHeapify(x);
}
void delHeapify(int in=1){
	int x=in<<1,y;
	y=x^1;
	bool f=false,ff=false;
	if(heap[in]>heap[x]){
		int tmp=heap[in];
		heap[in]=heap[x];
		heap[x]=tmp;
		f=true;
	}
	if(heap[in]>heap[y]){
		int tmp=heap[in];
		heap[in]=heap[y];
		heap[y]=tmp;
		ff=true;
	}
	if((ff && f) || ff) delHeapify(y);
	if(f) delHeapify(x);
}
void del(){
	if(index==0) return;
	heap[1]=heap[index];
	heap[index]=1e9;
	index--;
	if(index==0) return;
	delHeapify();
}
void insert(int val){
	index++;
	heap[index]=val;
	insertHeapify(index);
}
int main(){
	init();
	int n,x,action;
	cout<<"enter actions to be performed= insertions +deletion"<<endl;
	cin>>n;
	for(int i=n;i--;){
		cout<<"enter 1 for insertion 0 for deletion"<<endl;
		cin>>action;
		if(action!=0 && action!=1){
			cout<<"enter 1 for insertion 0 for deletion"<<endl;
			continue;
		}
		else if(action){
			cout<<"enter positive number to insert into MinHeap"<<endl;
			cin>>x;
			insert(x);
			cout<<"min element after insertion: "<<heap[1]<<endl;
		}
		else{
			del();
			if(heap[1]==INF) printf("minHeap is empty\n");
			else
			cout<<"min element after deletion: "<<heap[1]<<endl;
		}
	}
}
