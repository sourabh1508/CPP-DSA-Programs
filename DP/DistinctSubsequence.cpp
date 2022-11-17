#include<bits/stdc++.h>
using namespace std;

//Memoization
int memo(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = memo(i-1, j-1, s, t, dp) + memo(i-1, j, s, t, dp);
    return dp[i][j] = memo(i-1, j, s, t, dp); 
}

//Tabulation
int tab(string &s, string &t, int n, int m, vector<vector<int>> &dp){
    for(int j=0;j<=m;j++) dp[0][j] = 0;
    for(int i=0;i<=n;i++) dp[i][0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];       
            else dp[i][j] = dp[i-1][j];
        }
    }
   
    return dp[n][m]; 
}

//Space Optimization to 2 1D array
int SpaceOp(string &s, string &t, int n, int m){
    vector<int> prev(m+1, 0), cur(m+1, 0);

    prev[0] = 1;
    cur[0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]) cur[j] = prev[j-1] + prev[j];       
            else cur[j] = prev[j];
        }
        prev = cur;
    }
   
    return prev[m]; 
}

//Space Optimization to a single 1D array
int SpaceOpppp(string &s, string &t, int n, int m){
    vector<int> prev(m+1, 0);

    prev[0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(s[i-1] == t[j-1]) prev[j] = prev[j-1] + prev[j];
        }
    }
   
    return prev[m]; 
}

int main(){
    string s, t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int> (m, -1));    
    cout<<memo(n-1, m-1, s, t, dp)<<endl;
    vector<vector<int>> dp1(n+1, vector<int> (m+1, 0));    
    cout<<tab(s, t, n, m, dp1)<<endl;
    cout<<SpaceOp(s, t, n, m)<<endl;
    cout<<SpaceOpppp(s, t, n, m)<<endl;
}
