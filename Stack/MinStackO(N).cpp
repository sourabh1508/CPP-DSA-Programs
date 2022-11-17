#include<bits/stdc++.h>
using namespace std;
    
    int minEle;
    stack<int> s;
    stack<int> ss;
    
       /*returns min element from stack*/
        int getMin(){
            if(ss.empty())
                return -1;
            return ss.top();
          
        }
       
       /*returns poped element from stack*/
        int pop(){
            if(s.empty())
                return -1;
            int ans = s.top();
            s.pop();
            if(ss.top() == ans)
                ss.pop();
            return ans;
        }
       
       /*push element x into the stack*/
        void push(int x){
           
            s.push(x);
            if(ss.empty() || ss.top() >= x)
                ss.push(x);
            return;
        }

int main(){
    push(2);
    push(3);
    cout<<pop();
    cout<<getMin();
    push(1);
    cout<<getMin();
}