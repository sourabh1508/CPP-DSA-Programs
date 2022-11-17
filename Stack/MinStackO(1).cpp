#include<bits/stdc++.h>
using namespace std;

int minele = 0;

void push(stack<int>& s, int a){
	if(s.empty()){
	    s.push(a);
	    minele = a;
	}
	else{
	    if(minele <= a){
	        s.push(a);
    	}
    	else if(a < minele){
    	    s.push(2*a - minele);
    	    minele = a;
    	}
	}

	return;
}

bool isFull(stack<int>& s,int n){
	return n-1==s.size();
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	if(s.empty())
	    return -1;
	else{
	    if(minele <= s.top()){
	        int ans = s.top();
    	    s.pop();
    	    return ans;
	    }
    	else if(minele > s.top()){
    	    minele = 2*minele - s.top();
    	    s.pop();
    	    return minele;
    	}
	}
	
}

int getMin(stack<int>& s){
	if(s.empty())
	    return -1;
	return minele;
}

int main(){
    stack<int> s;
    push(s,2);
    push(s,3);
    cout<<pop(s);
    cout<<getMin(s);
    push(s,1);
    cout<<getMin(s);
}