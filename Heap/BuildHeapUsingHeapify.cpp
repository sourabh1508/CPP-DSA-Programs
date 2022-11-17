#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    
    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(arr, n, i);
}

void printHeap(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {10, 30, 50, 20, 35, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    buildHeap(arr, n);
    printHeap(arr, n);
    return 0;
}