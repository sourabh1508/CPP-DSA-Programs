#include<bits/stdc++.h>
using namespace std;

void MinToMaxHeap(int arr[], int n){
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = 10; 
    MinToMaxHeap(arr, n);
    cout<<endl;
    buildHeap(arr, n);
    printArray(arr, n);
    cout<<endl;
    return 0;
}