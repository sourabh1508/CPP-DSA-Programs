#include<bits/stdc++.h>
using namespace std;

    //Memoization
    int memo(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = 0 + memo(i-1, j-1, s, t, dp);
        }
        else{
            int Insert = 1 + memo(i, j-1, s, t, dp); 
            int Delete = 1 + memo(i-1, j, s, t, dp);
            int Replace = 1 + memo(i-1, j-1, s, t, dp);
            
            return dp[i][j] = min(Insert, min(Delete, Replace));
        }
    }

    //Tabulation
    int tab(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else{
                    int Insert = 1 + dp[i][j-1]; 
                    int Delete = 1 + dp[i-1][j];
                    int Replace = 1 + dp[i-1][j-1];
                    
                    dp[i][j] = min(Insert, min(Delete, Replace));
                }
            }
        }
        return dp[n][m];
    }

    //Space Optimization
    int SpaceOp(string &s, string &t, int n, int m){
        vector<int> prev(m+1, 0), cur(m+1, 0);

        for(int i=0;i<=n;i++) cur[0] = i;
        for(int j=0;j<=m;j++) prev[j] = j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = 0 + prev[j-1];
                }
                else{
                    int Insert = 1 + cur[j-1]; 
                    int Delete = 1 + prev[j];
                    int Replace = 1 + prev[j-1];
                    
                    cur[j] = min(Insert, min(Delete, Replace));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    
    int main() {
        string word1, word2;
        cin>>word1>>word2;
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        cout<<memo(n-1, m-1, word1, word2, dp)<<endl;
        vector<vector<int>> dp2(n+1, vector<int>(m+1, 0));
        cout<<tab(word1, word2, n, m, dp2)<<endl;
        cout<<SpaceOp(word1, word2, n, m)<<endl;
    }

