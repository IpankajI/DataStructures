#include<bits/stdc++.h>
using namespace std;
const int N=1e5,INF=-1e9;
int heap[N];
static int index=0;
void init(){
	for(int i=N;i--;) heap[i]=INF;
}
void insertHeapify(int in){
	int i=in>>1,ii;
	ii=in^1;
	bool f=false;
	if(i==0) return;
	if(heap[i]<heap[in]){
		int tmp=heap[i];
		heap[i]=heap[in];
		heap[in]=tmp;
		f=true;
	}
	if(heap[i]<heap[ii]){
		int tmp=heap[i];
		heap[i]=heap[ii];
		heap[ii]=tmp;
		f=true;
	}
	if(f) insertHeapify(i);
}
void insert(int val){
	index++;
	heap[index]=val;
	insertHeapify(index);
}
void delHeapify(int in=1){
	int x=in<<1,y;
	y=x+1;
	bool f=false,ff=false;
	if(heap[in]<heap[x]){
		int tmp=heap[in];
		heap[in]=heap[x];
		heap[x]=tmp;
		f=true;
	}
	if(heap[in]<heap[y]){
		int tmp=heap[in];
		heap[in]=heap[y];
		heap[y]=tmp;
		ff=true;
	}
	if((ff && f) || ff) delHeapify(y);
	else if(f) delHeapify(x);
}
void del(){
	if(index==0) return;
	heap[1]=heap[index];
	heap[index]=INF;
	index--;
	if(index==0) return;
	delHeapify();
}
int main(){
	init();
	int n,m,x,action;
	cout<<"enter number of operations to be performed= insertions + deletion"<<endl;
	cin>>n;
	for(int i=n;i--;){
		cout<<"enter 1 for insertion 0 for deletion"<<endl;
		cin>>action;
		if(action!=0 && action!=1) {
			i++;
			continue;
		}
		if(action==1){
			cout<<"enter positive number to insert"<<endl<<endl;
			cin>>x;
			insert(x);
			cout<<"max heap element: "<<heap[1]<<endl;
		}
		else{
			del();
			if(heap[1]==INF) printf("maxHeap is empty\n");
			else
			cout<<"max heap element after deletion: "<<heap[1]<<endl;
		}
	}
}
