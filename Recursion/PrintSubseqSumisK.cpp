#include<bits/stdc++.h>
using namespace std;

void f(int i, vector<int> &v, int s, int k, int arr[], int n){
    if(i==n){
        if(s==k){
            for(auto it: v)
                cout<<it<<" ";
            cout<<endl;
        }
        
        return;
    }
    v.push_back(arr[i]);
    f(i+1, v, s+arr[i], k, arr, n);

    v.pop_back();
    f(i+1, v, s, k, arr, n); 
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<int> v;
    int s=0;
    f(0, v, s, k, arr, n);
}