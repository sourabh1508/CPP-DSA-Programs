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

//Tabulation
bool tab(int n, int target, int arr[], vector<vector<bool>> &dp){
    for(int i=0;i<n;i++) dp[i][0] = true;
    if(arr[0]<=target) dp[0][arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(arr[i]<=j) take = dp[i-1][j-arr[i]];
            dp[i][j] = notTake || take;
        }
    }
    return dp[n-1][target];
}

//Space Optimization
bool Op(int n, int target, int arr[]){
    vector<bool> prev(target+1, 0), cur(target+1, 0); 
    prev[0] = cur[0] = true;
    if(arr[0]<=target) prev[arr[0]] = true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake = prev[j];
            bool take = false;
            if(arr[i]<=j) take = prev[j-arr[i]];
            cur[j] = notTake || take;
        }
        prev = cur;
    }
    return prev[target];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    cout<<memo(n-1, k, arr, dp)<<endl;
    vector<vector<bool>> dp1(n+1, vector<bool> (k+1, 0));
    cout<<tab(n, k, arr, dp1)<<endl;
    cout<<Op(n, k, arr);
}