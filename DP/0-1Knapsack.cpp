    #include<bits/stdc++.h>
    using namespace std;
    
    //Memoization
    int memo(int ind, int W, int wt[], int val[], vector<vector<int>> &dp){
        if(ind == 0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[ind][W]!=-1) return dp[ind][W];
        int notTake = 0 + memo(ind-1, W, wt, val, dp);
        int Take = INT_MIN;
        if(wt[ind]<=W) Take = val[ind] + memo(ind-1, W-wt[ind], wt, val, dp);
        
        return dp[ind][W] = max(notTake, Take);
    }

    //Tabulation
    int tab(int n, int W, int wt[], int val[], vector<vector<int>> &dp){
        for(int w=wt[0];w<=W;w++) dp[0][w] = val[0];
        
        for(int ind=1;ind<n;ind++){
            for(int w=0;w<=W;w++){
                int notTake = 0 + dp[ind-1][w];
                int Take = INT_MIN;
                if(wt[ind]<=w) Take = val[ind] + dp[ind-1][w-wt[ind]];
                dp[ind][w] = max(notTake, Take);
            }
        }
        return dp[n-1][W]; 
    }

    //Space Optimized in 2 1D arrays
    int SpaceOp(int n, int W, int wt[], int val[]){
        vector<int> prev(W+1, 0), cur(W+1, 0); 
        for(int i=wt[0];i<=W;i++) prev[i] = val[0];
        
        for(int ind=1;ind<n;ind++){
            for(int w=0;w<=W;w++){
                int notTake = 0 + prev[w];
                int Take = INT_MIN;
                if(wt[ind]<=w) Take = val[ind] + prev[w-wt[ind]];
                cur[w] = max(notTake, Take);
            }
            prev = cur;
        }
        return prev[W]; 
    }

    //Space Optimized in a single 1D array
    int SpaceOpppp(int n, int W, int wt[], int val[]){
        vector<int> prev(W+1, 0); 
        for(int i=wt[0];i<=W;i++) prev[i] = val[0];
        
        for(int ind=1;ind<n;ind++){
            for(int w=W;w>=0;w--){
                int notTake = 0 + prev[w];
                int Take = INT_MIN;
                if(wt[ind]<=w) Take = val[ind] + prev[w-wt[ind]];
                prev[w] = max(notTake, Take);
            }
        }
        return prev[W]; 
    }
    
    int main(){
        int n, W;
        cin>>n>>W;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];

        vector<vector<int>> dp(n, vector<int> (W+1,-1));
        cout<<memo(n-1, W, wt, val, dp)<<endl;
        vector<vector<int>> dp1(n, vector<int> (W+1, 0));
        cout<<tab(n, W, wt, val, dp1)<<endl;
        cout<<SpaceOp(n, W, wt, val)<<endl;
        cout<<SpaceOpppp(n, W, wt, val)<<endl;
    }