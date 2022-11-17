#include<bits/stdc++.h>
using namespace std;

//Memoization
int memo(int ind1, int ind2, string &text1, string &text2, vector<vector<int>> &dp){
    if(ind1<0 || ind2<0) return 0;
    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    
    if(text1[ind1] == text2[ind2]) return dp[ind1][ind2] = 1 + memo(ind1-1, ind2-1, text1, text2, dp);
    
    return dp[ind1][ind2] = 0 + max(memo(ind1-1, ind2, text1, text2, dp), memo(ind1, ind2-1, text1, text2, dp));
}

//Tabulation
int tab(string &text1, string &text2, int n, int m, vector<vector<int>> &dp){
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int j=0;j<=m;j++) dp[0][j] = 0;
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1] == text2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
    
            else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
        }
    }
    return dp[n][m];
}

//Space Optimization
int SpacOp(string &text1, string &text2, int n, int m){
    vector<int> prev(m+1, 0), cur(m+1, 0);
    for(int j=0;j<=m;j++) prev[j] = 0;
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(text1[ind1-1] == text2[ind2-1]) cur[ind2] = 1 + prev[ind2-1];
    
            else cur[ind2] = max(prev[ind2], cur[ind2-1]);
        }
        prev = cur;
    }
    return prev[m];
}

int main(){

    string text1, text2;
    cin>>text1>>text2;
    int l1 = text1.size();
    int l2 = text2.size();

    vector<vector<int>> dp(l1, vector<int> (l2, -1));
    cout<<memo(l1-1, l2-1, text1, text2, dp)<<endl; 
    vector<vector<int>> dp2(l1+1, vector<int> (l2+1, 0));
    cout<<tab(text1, text2, l1, l2, dp2)<<endl;
    cout<<SpacOp(text1, text2, l1, l2)<<endl; 
}