#include<bits/stdc++.h>
using namespace std;

//Memoization
int frogJumpK(int ind, vector<int> &heights, vector<int> &dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int ans = INT_MAX;
    for(int i=1;i<=k;i++){
        if(ind>=i){ 
            int jump = frogJumpK(ind-i, heights, dp, k) + abs(heights[ind]-heights[ind-i]);
            ans = min(ans, jump);
        }
    }
    return dp[ind] = ans; 
}

int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];
    vector<int> dp(n+1, -1);
    cout<<frogJumpK(n-1, heights, dp, 2);
}