#include<bits/stdc++.h>
using namespace std;

    //Memoization
    int memo(int i, int j, vector<vector<int>>& matrix, int n, int m, vector<vector<int>> &dp){
        if(j<0 || j>=m) return 1e8;
        if(i==0) return matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = matrix[i][j] + memo(i-1, j, matrix, n, m, dp);
        int leftdiag = matrix[i][j] + memo(i-1, j-1, matrix, n, m, dp);
        int rightdiag = matrix[i][j] + memo(i-1, j+1, matrix, n, m, dp);
        
        return dp[i][j] = min(up, min(leftdiag, rightdiag));
    }

    //Tabulation
    int tab(vector<vector<int>>& matrix, int n, int m, vector<vector<int>> &dp){
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j] + dp[i-1][j];  
                int leftdiag = matrix[i][j]; if(j-1>=0) leftdiag += dp[i-1][j-1]; else leftdiag += 1e9;
                int rightdiag = matrix[i][j]; if(j+1<m) rightdiag += dp[i-1][j+1]; else rightdiag += 1e9;

                dp[i][j] = min(up, min(leftdiag, rightdiag));
            }
        }
        int ans = 1e8;
        for(int j=0;j<m;j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }

    //Space Optimization
    int Op(vector<vector<int>>& matrix, int n, int m){
        vector<int> prev(m, 0);
        for(int j=0;j<m;j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1;i<n;i++){
            vector<int> cur(m);
            for(int j=0;j<m;j++){
                int up = matrix[i][j] + prev[j];  
                int leftdiag = matrix[i][j]; if(j-1>=0) leftdiag += prev[j-1]; else leftdiag += 1e9;
                int rightdiag = matrix[i][j]; if(j+1<m) rightdiag += prev[j+1]; else rightdiag += 1e9;

                cur[j] = min(up, min(leftdiag, rightdiag));
            }
            prev = cur;
        }
        int ans = 1e8;
        for(int j=0;j<m;j++){
            ans = min(ans, prev[j]);
        }
        return ans;
    }       

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> mat(n, vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int> (m, -1));
    int ans = 1e8;
    for(int j=0;j<m;j++){
        ans = min(ans, memo(n-1, j, mat, n, m, dp));
    }
    cout<<ans<<endl;
    vector<vector<int>> dp1(n, vector<int> (m, -1));
    cout<<tab(mat, n, m, dp1)<<endl;
    cout<<Op(mat, n, m)<<endl;
}
    