#include<iostream>
using namespace std;

int main()
{
    int n,i=0;
    int arr[10];
    cin>>n;
    while(n!=0)
    {
        arr[i]=n%2;
        n=n/2;
        i++;
    }
    for(int j=i-1;j>=0;j--)
    {
        cout<<arr[j];
    }
    


    return 0;
}