#include<bits/stdc++.h>
using namespace std;

//Memoization
bool memo(int i, int target, int arr[], vector<vector<int>> &dp){
    if(target==0) return true;
    if(i==0) return (arr[0]==target);

    if(dp[i][target] != -1) return dp[i][target];

    bool notTake = memo(i-1, target, arr, dp);
    bool take = false;
    if(arr[i]<=target) take = memo(i-1, target-arr[i], arr, dp);

    return dp[i][target] = notTake || take;
}

int minDifference(int arr[], int n){
    int totalSum = 0;
    for(int i=0;i<n;i++) 
        totalSum += arr[i];
    
    
    vector<vector<int>> dp(n, vector<int> (totalSum+1, -1));

    for(int i=0;i<=totalSum;i++){
       bool fl = memo(n-1, i, arr, dp); 
    }

    int mini = 1e9;
    for(int i=0;i<=totalSum/2;i++){
        if(dp[n-1][i] == true){
            int s1 = i;
            int s2 = totalSum - i; 
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Minimum Difference is "<<minDifference(arr, n);
}
