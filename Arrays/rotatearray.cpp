#include<iostream>
using namespace std;

void rotateArray(int arr[],int n,int p)
{
    for(int i=0;i<n;i++)
    {   if(i+p<n)
            arr[i] = arr[i+p];
        else{ 
            arr[i] = arr[n-i-p];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
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

    int p;
    cin>>p;

    rotateArray(arr,n,p);
    return 0;
}