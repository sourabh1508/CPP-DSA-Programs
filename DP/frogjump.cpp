#include<bits/stdc++.h>
using namespace std;

//Memoization
int frogJumpMemo(int ind, vector<int> &heights, vector<int> &dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int left = frogJumpMemo(ind-1, heights, dp) + abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1)
        right = frogJumpMemo(ind-2, heights, dp) + abs(heights[ind]-heights[ind-2]);
    
    return dp[ind] = min(left,right);
}

//Tabulation
int frogJumpTab(vector<int> &heights, vector<int> &dp){
    dp[0] = 0;
    for(int i=1;i<heights.size();i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1) right = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(left, right);
    }
    return dp[heights.size()-1];
}

//Space Optimized
int frogJumpOp(vector<int> &heights){
    int prev = 0, prev2 = 0;
    for(int i=1;i<heights.size();i++){
        int left = prev + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1) right = prev2 + abs(heights[i]-heights[i-2]);
        int cur = min(left, right);
        prev2 = prev;
        prev = cur;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];
    vector<int> dp1(n, -1);
    cout<<frogJumpMemo(n-1, heights, dp1)<<endl;
    vector<int> dp2(n, -1);
    cout<<frogJumpTab(heights, dp2)<<endl;
    cout<<frogJumpOp(heights)<<endl;
    return 0;
}