#include<bits/stdc++.h>
using namespace std;

    //Memoization
        int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + memo(i-1, j, grid, dp);
        int left = grid[i][j] + memo(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);
        
    }

    //Tabulation
    int tab(int m, int n, vector<vector<int>>& grid, vector<vector<int>> &dp){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int up = 1e9;
                    int left = 1e9;
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    if(j>0) left = grid[i][j] + dp[i][j-1];

                    dp[i][j] = min(up,left);    
                }        
            }
        }
        return dp[m-1][n-1];
    }

    //Space Optimized
    int Op(int m, int n, vector<vector<int>>& grid){
        vector<int> prev(n, 0); //previous row
        
        for(int i=0;i<m;i++){
            vector<int> cur(n, 0); //current row
            for(int j=0;j<n;j++){
                if(i==0 && j==0) cur[j] = grid[i][j];
                else{
                    int up = 1e9;
                    int left = 1e9;
                    if(i>0) up = grid[i][j] + prev[j];
                    if(j>0) left = grid[i][j] + cur[j-1];

                    cur[j] = min(up,left);    
                }      
            }
            prev = cur;
        }
        return prev[n-1];
    }

    int main(){
        int m, n;
        cin>>m>>n;
        vector<vector<int>> grid(m, vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        vector<vector<int>> dp(m, vector<int> (n, -1));
        cout<<memo(m-1, n-1, grid, dp)<<endl; 
        vector<vector<int>> dp1(m, vector<int> (n));
        cout<<tab(m, n, grid, dp1)<<endl;
        cout<<Op(m, n, grid);
    }