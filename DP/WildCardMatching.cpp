#include<bits/stdc++.h>
using namespace std;

    //Memoization
    bool memo(int i, int j, string &t, string &s, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int ii=0;ii<=i;ii++){
                if(t[ii] != '*') return false;
            }
            return true;
        } 
         
        if(dp[i][j] != -1) return dp[i][j];
        
        if(t[i] == s[j] || t[i] == '?') return dp[i][j] = memo(i-1, j-1, t, s, dp);
        if(t[i] == '*') return dp[i][j] = memo(i-1, j, t, s, dp) || memo(i, j-1, t, s, dp);
        
        return dp[i][j] = false;
    }

    //Tabulation
    bool tab(string &t, string &s, int n, int m, vector<vector<bool>> &dp){
        dp[0][0] = true;
        for(int j=1;j<=m;j++) dp[0][j] = false;
        
        for(int i=1;i<=n;i++){
            for(int ii=1;ii<=i;ii++){
                if(t[ii] != '*'){
                    dp[i][0] = false;
                    break;
                } 
            }
            dp[i][0] = true;
        }
        
        
         
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t[i-1] == s[j-1] || t[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(t[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }

    //Space Optimization
    bool SpaceOp(string &t, string &s, int n, int m){
        vector<bool> prev(m+1, false), cur(m+1, false);
        prev[0] = true;
        for(int j=1;j<=m;j++) prev[j] = false;
        
        for(int i=1;i<=n;i++){
            for(int ii=1;ii<=i;ii++){
                if(t[ii-1] != '*'){
                    cur[0] = false;
                    break;
                } 
            }
            cur[0] = true;
            for(int j=1;j<=m;j++){
                if(t[i-1] == s[j-1] || t[i-1] == '?') cur[j] = prev[j-1];
                else if(t[i-1] == '*') cur[j] = prev[j] || cur[j-1];
                else cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
    }

    int main(){
        string t, s;
        cin>>t>>s;

        int n = t.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        cout<<memo(n-1, m-1, t, s, dp)<<endl;
        vector<vector<bool>> dp2(n+1, vector<bool> (m+1, false));
        cout<<tab(t, s, n, m, dp2)<<endl;
        cout<<SpaceOp(t, s, n, m)<<endl;
    }