#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n+1];
    a[n] = -1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    if(n == 1)
    {
        cout<<"1"<<endl;
        return 0;
    }

    int c=0;
    int mx = -1;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]>mx && a[i]>a[i+1])
            c++;
        mx = max(mx,a[i]);
    }
    cout<<c<<endl;
    return 0;
}