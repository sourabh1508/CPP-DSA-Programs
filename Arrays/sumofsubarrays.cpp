#include<bits/stdc++.h>
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

    int currsum=0;

    for(int i=0;i<n;i++)
    {
        currsum=0;
        for(int j=i;j<n;j++)
        {
            currsum+=arr[j];
            cout<<currsum<<" ";
        }
        cout<<endl;
    }
    return 0;
}