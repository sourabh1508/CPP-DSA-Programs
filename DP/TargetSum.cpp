#include<bits/stdc++.h>
using namespace std; 
    
    
    int memo(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(ind==0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            else return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];

        int notPick = memo(ind-1, target, arr, dp);
        int Pick = 0;
        if(arr[ind]<=target) Pick = memo(ind-1, target-arr[ind], arr, dp);

        return dp[ind][target] = notPick + Pick;
    }

int main(){
    int n, target;
    cin>>n>>target;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    int TS = 0;
    for(int i=0;i<n;i++) TS += arr[i];
    if(TS-target < 0 || (TS-target)%2 == 1) return 0;
        
    vector<vector<int>> dp(n+1, vector<int> ((TS - target)/2 + 1, -1));
    cout<<memo(n-1, (TS - target)/2, arr, dp)<<endl;
}