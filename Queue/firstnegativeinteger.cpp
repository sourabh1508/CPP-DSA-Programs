#include<bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> ans;
    deque<long long int> dq;
    
    for(int i=0;i<K;i++){
        if(A[i]<0)
            dq.push_back(i);
    }
    
    if(!dq.empty()){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    for(int i=K;i<N;i++){
        if(!dq.empty() && i-dq.front()>=K)
            dq.pop_front();
        
        if(A[i]<0)
            dq.push_back(i);
        
        if(!dq.empty()){
            ans.push_back(A[dq.front()]);
        }
         else{
            ans.push_back(0);
        }
    }
    return ans;
 }

 int main(){
     long long int A[] = {-8, 2, 3, -6, 10};
     long long int N = 5;
     long long int K = 2;
     vector<long long int> v = printFirstNegativeInteger(A, N, K);
     for(int i=0;i<v.size();i++){
         cout<<v[i]<<" ";
     }
 }
