// https://www.spoj.com/problems/HORRIBLE/
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+1;

ll query(int idx, ll bit[]){

	ll res = 0ll;
	while(idx >0){
		res += bit[idx];
		idx -= idx&(-idx);
	}
	return res;
}

ll getSum(int idx, ll bit1[], ll bit2[]){

	return query(idx, bit1)*idx - query(idx, bit2);
}

ll getRangeSum(int p, int q, ll bit1[], ll bit2[]){

	return getSum(q, bit1, bit2) - getSum(p-1, bit1, bit2);
}

void update(int idx, ll v, int n, ll bit[]){
	while(idx <= n){
		bit[idx] += v;
		idx += idx&(-idx);	
	}
}

void updateRange(int p, int q, int v, int n, ll bit1[], ll bit2[]){

	update(p, v, n, bit1);
	update(q+1, -v, n, bit1);

	update(p, 1ll*v*(p-1), n, bit2);
	update(q+1, -1ll*q*v, n, bit2);
}

int main(){
	ios::sync_with_stdio(0);
	freopen("../input", "r", stdin);
	int t;
	ll bit1[N], bit2[N];
	cin>>t;
	while(t--){
		int n,c;
		cin>>n>>c;
		memset(bit1, 0ll, N*sizeof(ll));
		memset(bit2, 0ll, N*sizeof(ll));
		while(c--){
			int one,p,q,v;
			cin>>one;
			if(one){
				cin>>p>>q;
				cout<<getRangeSum(p,q, bit1, bit2)<<endl;
			}
			else{
				cin>>p>>q>>v;
				updateRange(p, q, v, n, bit1, bit2);
			}			
		}
	}
}
