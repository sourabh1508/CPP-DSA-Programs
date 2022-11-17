#include<bits/stdc++.h>
using namespace std;

   int memo(int ind, int n, int price[], vector<vector<int>> &dp){
        if(ind == 0){
            return (n/1)*price[0];
        }
        if(dp[ind][n] != -1) return dp[ind][n];
        int notTake = 0 + memo(ind-1, n, price, dp);
        int take = INT_MIN;
        if(ind+1 <= n) take = price[ind] + memo(ind, n - (ind+1), price, dp);
        
        return dp[ind][n] = max(notTake, take);
    }
  
    int main(){
        int n;
        cin>>n;

        int price[n];
        for(int i=0;i<n;i++){
            cin>>price[i];
        }
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        cout<<memo(n-1, n, price, dp)<<endl;
    }