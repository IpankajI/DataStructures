#include<bits/stdc++.h>
using namespace std;
class Q{
	private:
		stack<int> st1,st2;
    public:
        void push(int x) {
             st1.push(x);      
        }
        void pop() {
            if(!st2.empty()){
                st2.pop();
                return ;
            }
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
        }
        int front() {
            if(!st2.empty()) return st2.top();
            int x;
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            if(!st2.empty())
            x=st2.top();
            return x;
        }
};

int main() {
    Q q;
    int t,type,x;
    cin>>t; 				//total number of operations (pop+front+push)
    while(t--){
    	cin>>type;
        if(type==1) {
            cin>>x;
            q.push(x);
        }
        else if(type==2) {
            q.pop();
        }
        else cout<<q.front()<<endl;
	}
    return 0;
}

