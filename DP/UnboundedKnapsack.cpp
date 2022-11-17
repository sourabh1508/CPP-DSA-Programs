#include<bits/stdc++.h>
using namespace std;

//Memoization
int memo(int ind, int w, int profit[], int weight[], vector<vector<int>> &dp){
    if(ind == 0){
        if(weight[0]<=w) return (w/weight[0])*profit[0];
        else return 0;
    }
    if(dp[ind][w] != -1) return dp[ind][w];
    
    int notTake = 0 + memo(ind-1, w,  profit, weight, dp);
    int take = -1e8;
    if(weight[ind]<=w) take = profit[ind] + memo(ind, w-weight[ind], profit, weight, dp);
    
    return dp[ind][w] = max(notTake, take);
}

//Tabulation
int tab(int n, int W, int profit[], int weight[], vector<vector<int>> &dp){
    for(int w=weight[0];w<=W;w++) dp[0][w] = (w/weight[0])*profit[0];
        
    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=W;w++){
            int notTake = 0 + dp[ind-1][w];
            int Take = INT_MIN;
            if(weight[ind]<=w) Take = profit[ind] + dp[ind][w-weight[ind]];
            dp[ind][w] = max(notTake, Take);
        }
    }
    return dp[n-1][W]; 
}

//Space Optimized in 2 1D arrays
int SpaceOp(int n, int W, int profit[], int weight[]){
    vector<int> prev(W+1, 0), cur(W+1, 0); 
    for(int w=weight[0];w<=W;w++) prev[w] = (w/weight[0])*profit[0];
        
    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=W;w++){
            int notTake = 0 + prev[w];
            int Take = INT_MIN;
            if(weight[ind]<=w) Take = profit[ind] + cur[w-weight[ind]];
            cur[w] = max(notTake, Take);
        }
        prev = cur;
    }
    return prev[W]; 
}

//Space Optimized in a single 1D array
int SpaceOpppp(int n, int W, int profit[], int weight[]){
    vector<int> prev(W+1, 0); 
    for(int w=weight[0];w<=W;w++) prev[w] = (w/weight[0])*profit[0];
        
    for(int ind=1;ind<n;ind++){
        for(int w=W;w>=0;w--){
            int notTake = 0 + prev[w];
            int Take = INT_MIN;
            if(weight[ind]<=w) Take = profit[ind] + prev[w-weight[ind]];
            prev[w] = max(notTake, Take);
        }
    }
    return prev[W]; 
}


int main(){
    int n, W;
    cin>>n>>W;
        
    int profit[n];
    int weight[n];
        
    //inserting the profits
    for(int i=0;i<n;i++)
        cin>>profit[i];
        
    //inserting the weights
    for(int i=0;i<n;i++)
        cin>>weight[i];

    vector<vector<int>> dp(n, vector<int> (W+1,-1));
    cout<<memo(n-1, W, profit, weight, dp)<<endl;
    vector<vector<int>> dp1(n, vector<int> (W+1, 0));
    cout<<tab(n, W, profit, weight, dp1)<<endl;
    cout<<SpaceOp(n, W, profit, weight)<<endl;
    cout<<SpaceOpppp(n, W, profit, weight)<<endl;
    }