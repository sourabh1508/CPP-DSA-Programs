#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int nge[n];
    stack<int> st;

    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i%n]){
            st.pop();
        }
        if(!st.empty()){
            nge[i%n] = st.top();
        }
        else{
            nge[i%n] = -1;
        }
        st.push(arr[i%n]);
    }

    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }
    return 0;
}