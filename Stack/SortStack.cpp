#include<bits/stdc++.h>
using namespace std;

void sortedStack(stack<int> &s, int e){
    if(s.empty() || (!s.empty() && e > s.top())){
        s.push(e);
        return;
    }
    int t = s.top();
    s.pop();
    
    sortedStack(s, e);
    
    s.push(t);
}

void sort(stack<int> &s){
    if(s.empty()){
       return;
   }
   int e = s.top();
   s.pop();
   
   sort(s);
   
   sortedStack(s, e);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(42);
    s.push(25);
    s.push(32);
    s.push(15);
    sort(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}