#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A){
		    queue<char> q;
		    map<char,int> m;
		    string res;
		    for(int i=0;i<A.length();i++){
		        m[A[i]]++;
		        q.push(A[i]);
		    
    		    while(!q.empty()){
    		        if(m[q.front()]==1){
    		            res += q.front();
    		            break;
    		        }
    		        else if(m[q.front()]>1){
    		            q.pop();
    		        }
    		    }
    		    if(q.empty()){
    		        res += '#';
    		    }
		    }
		    return res;
		}

int main(){
    string s;
    cin>>s;
    cout<<FirstNonRepeating(s);
}