#include<iostream>
using namespace std;

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

    int st=0;
    int en=n-1;

    while(st<en)
    {
        if(arr[st]+arr[en]==k)
        {
            cout<<st<<" "<<en<<endl;
            return true;
        }
        else if(arr[st]+arr[en]>k)
        {
            en--;
        }
        else
        {
            st++;
        }
        
    }
    return false;

}