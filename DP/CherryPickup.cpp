#include<bits/stdc++.h>
using namespace std;

    //Memoization
    int memo(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e9;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = 0;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2) maxi = max(maxi, grid[i][j1] + memo(i+1, j1+dj1, j2+dj2, grid, n, m, dp));
                else maxi = max(maxi, grid[i][j1] + grid[i][j2] + memo(i+1, j1+dj1, j2+dj2, grid, n, m, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    //Tabulation
    int tab(vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>> &dp){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi = 0;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int value = 0;
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m) 
                                value += dp[i+1][j1+dj1][j2+dj2];
                            else value += -1e9;
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        
        return dp[0][0][m-1];
    }

    //Space Optimized
    int Op(vector<vector<int>>& grid, int n, int m){
        vector<vector<int>> front(m, vector<int> (m, 0)); 
        vector<vector<int>> cur(m, vector<int> (m, 0));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) front[j1][j2] = grid[n-1][j1];
                else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi = 0;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            int value = 0;
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];
                            
                            if(j1+dj1 >= 0 && j1+dj1 < m && j2+dj2 >= 0 && j2+dj2 < m) 
                                value += front[j1+dj1][j2+dj2];
                            else value += -1e9;
                            maxi = max(maxi, value);
                        }
                    }
                    cur[j1][j2] = maxi;
                }
            }
            front = cur;
        }
        
        return front[0][m-1];
    }

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m, -1)));
    cout<<memo(0, 0, m-1, grid, n, m, dp)<<endl;  
    vector<vector<vector<int>>> dp1(n, vector<vector<int>> (m, vector<int> (m, -1)));
    cout<<tab(grid, n, m, dp1)<<endl;
    cout<<Op(grid, n, m)<<endl;  
}