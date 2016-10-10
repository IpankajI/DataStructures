#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=200005;
ll BIT[N],n,arr[N];
void update(ll in,ll value){
	for( ;in<=n;in+=in&(-in)) BIT[in]+=value;
}
ll query(ll id){
	ll res=0;
	for(;id>0;id-=id&(-id)) res+=BIT[id];
	return res;
}
int main(){
	int x,q,upto;
	printf("Enter number of elements (n) and number of queries (q)\n");
	cin>>n>>q;
	printf("enter %d integers elements\n",n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		update(i,x);
	}
	for(int i=q;i--;){
		cout<<"enter index number to get sum upto( starts at 1)"<<endl;
		scanf("%d",&upto);
		printf("sum upto %d elements: %d\n",upto,query(upto));
	}
}
