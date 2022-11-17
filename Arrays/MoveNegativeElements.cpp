#include<bits/stdc++.h>
using namespace std;

//Dutch National Flag Algorithm
void f(int arr[], int n){
    int low = 0;
    int high = n-1;

    while(low<high){
        if(arr[low]<0) low++;
        else if(arr[high]>0) high--;
        else swap(arr[low++], arr[high--]);
    }
}

int main(){
    int n; 
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];
    f(arr, n);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}