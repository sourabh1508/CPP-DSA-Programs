#include<bits/stdc++.h>
using namespace std;

void deletion(int arr[], int n){
    arr[1] = arr[n];
    n = n-1;
    int i=1;
    while(i<n){
        int left = 2*i;
        int right = 2*i+1;

        if(left<n && arr[left] > arr[i]){
            swap(arr[i], arr[left]);
            i = left;
        }
        else if(right<n && arr[right] > arr[i]){
            swap(arr[i], arr[right]);
            i = right;
        }
        else return;
    }
}

void printHeap(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

int main(){
    int arr[] = {-1, 10, 5, 3, 2, 4};
    int n = 5;
    deletion(arr, n);
    printHeap(arr, n);
}