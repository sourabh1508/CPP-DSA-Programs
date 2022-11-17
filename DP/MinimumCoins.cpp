#include<bits/stdc++.h>
using namespace std;

    //Memoization
    int memo(int ind, int target, vector<int>& coins, vector<vector<int>> &dp){
        if(ind == 0){
            if(target%coins[ind]==0) return target/coins[ind];
            else return 1e9;
        } 
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTake = 0 + memo(ind-1, target, coins, dp);
        int take = 1e9;
        if(target >= coins[ind]) take = 1 + memo(ind, target - coins[ind], coins, dp);
        
        return dp[ind][target] = min(take, notTake);
    }

int main(){
    int n, t;
    cin>>n>>t;
    
    vector<int> coins(n);
    for(int i=0;i<n;i++)
        cin>>coins[i];
        
    vector<vector<int>> dp(n, vector<int> (t+1,-1));
    int ans = memo(n-1, t, coins, dp);
    if(ans >= 1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}