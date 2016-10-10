#include<bits/stdc++.h>
using namespace std;
int root(int node[],int i){
	while(node[i]!=i){
		node[i]=node[node[i]];
		i=node[i];
	}
	return i;
}
void weighted_union(int node[],int size[],int a,int b){
	int root_a=root(node,a);
	int root_b=root(node,b);
	if(root_a!=root_b){ //when parent isn't same
		if(size[root_a]<=size[root_b]){
			node[root_a]=node[root_b];
			size[root_b]+=size[root_a];
		}
		else{
			node[root_b]=node[root_a];
			size[root_a]+=size[root_b];
		}
	}
}
int main(){
	int n,d,a,b,node[10005],size[10005],ans=1000,tmp,in,q;
	printf("enter number of elements in set, numbers of union and query operations  to be performed\n");
	scanf("%d %d %d",&n,&d,&q);
	for(int i=1;i<=n;i++) {
		node[i]=i;
		size[i]=1;
	}
	for(int i=d;i--;){
		printf("enter elements for union\n");
		scanf("%d %d",&a,&b);
		weighted_union(node,size,a,b);
	}
	for(int i=q;i--;) {
		printf("enter two elements to check whther they are in same set\n");
		scanf("%d %d",&a,&b);
		if(root(node,a)==root(node,b)) printf("%d and %d are in same set\n",a,b);
		else printf("%d and %d are not in same set\n",a,b);
	}
}
