#include<bits/stdc++.h>
using namespace std;

    //Memoization
    int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>> &dp){
        if(i==n-1) return triangle[n-1][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = triangle[i][j] + f(i+1, j, triangle, n, dp);
        int diag = triangle[i][j] + f(i+1, j+1, triangle, n, dp);
        
        return dp[i][j] = min(down, diag);
    }

    //Tabulation
    int tab(vector<vector<int>>& triangle, int n, vector<vector<int>> &dp){
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }

    //Space Optimization
    int Op(vector<vector<int>>& triangle, int n){
        
        vector<int> prev(n);
        for(int j=0;j<n;j++){
            prev[j] = triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            vector<int> cur(n-1);
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j+1];

                cur[j] = min(down, diag);
            }
            prev = cur;
        }
        return prev[0];
    }

int main(){
    int n;
    cin>>n;
    vector<vector<int>> triangle(n, vector<int> (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>triangle[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout<<f(0, 0, triangle, n, dp)<<endl;
    vector<vector<int>> dp1(n, vector<int> (n, -1));
    cout<<tab(triangle, n, dp1)<<endl;
    cout<<Op(triangle, n);
}