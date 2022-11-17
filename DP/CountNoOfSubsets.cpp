#include<bits/stdc++.h>
using namespace std;

//Memoization
int memo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0) return 1;
    if(ind == 0){
        if(arr[0] == target) return 1;
        else return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];

    int notPick = memo(ind-1, target, arr, dp);
    int Pick = 0;
    if(arr[ind]<=target) Pick = memo(ind-1, target-arr[ind], arr, dp);

    return dp[ind][target] = notPick + Pick;
}

//Tabulation
int tab(int n, int target, vector<int> &arr, vector<vector<int>> &dp){
    for(int i=0;i<n;i++) dp[i][0] = 1;
    if(arr[0]<=target) dp[0][arr[0]] = 1;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            int notTake = dp[i-1][j];
            int take = 0;
            if(arr[i]<=j) take = dp[i-1][j-arr[i]];
            dp[i][j] = notTake + take;
        }
    }
    return dp[n-1][target];
}

//Space Optimization
int Op(int n, int target, vector<int> &arr){
    vector<int> prev(target+1, 0), cur(target+1, 0); 
    prev[0] = cur[0] = 1;
    if(arr[0]<=target) prev[arr[0]] = 1;

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake = prev[j];
            bool take = 0;
            if(arr[i]<=j) take = prev[j-arr[i]];
            cur[j] = notTake + take;
        }
        prev = cur;
    }
    return prev[target];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
    cout<<memo(n-1, k, arr, dp)<<endl;
    vector<vector<int>> dp1(n, vector<int> (k+1, -1));
    cout<<tab(n-1, k, arr, dp1)<<endl;
    cout<<Op(n-1, k, arr);
}