#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
    {
         int b[r+1];
         int i=l;
         int j=mid+1;
         int k=l;
         
         while(i<=mid && j<=r){
             if(arr[i]<arr[j]){
                 b[k] = arr[i];
                 i++;
             }
             else{
                 b[k] = arr[j];
                 j++;
             }
             k++;
         }
         if(j>r){
             while(i<=mid){
                 b[k] = arr[i];
                 i++;
                 k++;
             }
         }
         if(i>mid){
            while(j<=r){
                 b[k] = arr[j];
                 j++;
                 k++;
             }
         }
         for(int i=l;i<=r;i++){
            arr[i] = b[i]; 
         }
    }
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid+1, r);
            
            merge(arr, l, mid, r);  
        }   
    }

    int main(){
        int n;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++) cin>>arr[i];

        mergeSort(arr, 0, n-1);

        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }