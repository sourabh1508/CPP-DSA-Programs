#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

void insertion(int arr[], int &n, int val){
    n=n+1;
    int i=n-1; //0 based indexing
    arr[i] = val;

    while(i>1){
        int parent = (i-1)/2;
        if(arr[i]>arr[parent]){
            swap(arr[i], arr[parent]);
            i = parent;
        }
        else return;     
    }
    
}

void printHeap(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[MAX] = {10, 5, 3, 2, 4};
    int n = 5;
    int val = 15;
    insertion(arr, n, val);
    printHeap(arr, n);
    cout<<endl;
    insertion(arr, n, 20);
    printHeap(arr, n);
}