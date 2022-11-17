#include<bits/stdc++.h>
using namespace std;

int kadence(int arr[], int n)
{
    int maxSum = INT_MIN;
    int currentSum = 0;
    for(int i=0;i<n;i++)
    {
        currentSum+=arr[i];
        if(currentSum<0)
        {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main()
{
    int n;
    cin>>n;

    int arr[n];
    int totalsum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        totalsum += arr[i];
    }
    int nonwrapsum;
    int wrapsum;

    nonwrapsum = kadence(arr,n);

    for(int i=0;i<n;i++)
    {
        arr[i]=-arr[i];
    }

    wrapsum = totalsum - (-kadence(arr,n));
    cout<<max(wrapsum,nonwrapsum);
    
    
    return 0;
}