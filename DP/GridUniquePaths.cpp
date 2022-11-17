#include<bits/stdc++.h>
using namespace std;

    //Memoization
    int memo(int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = memo(i-1, j, dp);
        int left = memo(i, j-1, dp);
        
        return dp[i][j] = up+left;
    }

    //Tabulation
    int tab(int m, int n, vector<vector<int>> &dp){
        dp[0][0] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = up + left;    
                }        
            }
        }
        return dp[m-1][n-1];
    }

    //Space Optimized
    int Op(int m, int n){
        vector<int> prev(n, 0); //previous row
        
        for(int i=0;i<m;i++){
            vector<int> cur(n, 0); //current row
            for(int j=0;j<n;j++){
                if(i==0 && j==0) cur[j] = 1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = cur[j-1];

                    cur[j] = up + left;    
                }      
            }
            prev = cur;
        }
        return prev[n-1];
    }

    int main(){
        int m, n;
        cin>>m>>n;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        cout<<memo(m-1, n-1, dp)<<endl; 
        vector<vector<int>> dp1(m, vector<int> (n));
        cout<<tab(m, n, dp1)<<endl;
        cout<<Op(m, n)  ;
    }