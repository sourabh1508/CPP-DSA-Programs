#include<bits/stdc++.h>
using namespace std;

void subsequences(int i, vector<int> &v, int arr[], int n){
    if(i == n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        if(v.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    

    v.push_back(arr[i]);
    subsequences(i+1, v, arr, n);
    v.pop_back();
    subsequences(i+1, v, arr, n);
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    subsequences(0, v, arr, n);
}