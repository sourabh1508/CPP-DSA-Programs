#include<iostream>
using namespace std;

int BinarySearch(int n,int arr[], int k)
{
    int s=0, e=n-1;

    while (s<=e)
    {
        int mid=(s+e)/2;
        
        if(k==arr[mid])
            return mid;
        else if(k<arr[mid])
            e=mid-1;
        else
            s=mid+1;
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    cout<<BinarySearch(n,arr,k)<<endl;
    return 0;
}