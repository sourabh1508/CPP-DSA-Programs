#include<bits/stdc++.h>
using namespace std;

int kLargest(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<k;i++)
        pq.push(arr[i]);
    for(int i=k;i<n;i++){
        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int kSmallest(int arr[], int n, int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
        pq.push(arr[i]);
    for(int i=k;i<n;i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    cout<<k<<" Largest Element:"<<kLargest(arr, n, k)<<endl;
    cout<<k<<" Smallest Element: "<<kSmallest(arr, n, k)<<endl;
    return 0;
}