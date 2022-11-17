#include<bits/stdc++.h>
using namespace std;

    int equilibriumPoint(long long a[], int n) {
    
        int pre[n], post[n];
        pre[0] = a[0];
        post[n-1] = a[n-1]; 
        
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + a[i];
        }
        for(int i=n-2;i>=0;i--){
            post[i] = post[i+1] + a[i];
        }
        
        for(int i=0;i<n;i++){
            if(pre[i] == post[i]) return i+1;
        }
        return -1;
    }

    int main(){
        int n;
        cin>>n;

        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<equilibriumPoint(arr, n);
    }
