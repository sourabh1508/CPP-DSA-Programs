#include<bits/stdc++.h>
using namespace std;

vector<int> f1(int arr[], int n){
    vector<int> temp(n, 0);
    vector<int> v;
    for(int i=0;i<n-1;i++) temp[arr[i]]++;
    for(int i=1;i<n;i++){
        if(temp[i] == 0 || temp[i] > 1) v.push_back(i);
    } 
    return v;
}

int main(){
    int n;
    cin>>n;

    int arr[n-1];
    for(int i=0;i<n-1;i++) cin>>arr[i];

    vector<int> v = f1(arr, n);
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
}