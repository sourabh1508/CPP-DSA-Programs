#include<bits/stdc++.h>
using namespace std;

    bool isValid(int A[], int N, int M, int allowed){
        int s=0;
        int c=1;
        for(int i=0;i<N;i++){
            if(s+A[i]>allowed){
                c++;
                s = A[i];
            }
            else{
                s += A[i];  
            }
        }
        if(c>M) return false;
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(N<M) return -1;
        int mx = INT_MIN;
        int s=0;
        
        for(int i=0;i<N;i++){
            s += A[i];
            mx = max(mx, A[i]);
        }
        int st = mx;
        int en = s;
        int res = -1;
        
        while(st<=en){
            int mid = st + (en-st)/2;
            if(isValid(A, N, M, mid)){
                res = mid;
                en = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return res;
    }

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++) cin>>A[i];

    cout<<findPages(A, n, 2);
}