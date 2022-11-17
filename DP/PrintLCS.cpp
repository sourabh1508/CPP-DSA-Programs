#include<bits/stdc++.h>
using namespace std;

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

int main(){
    string text1, text2;
    cin>>text1>>text2;
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    int len = tab(text1, text2, n, m, dp);

    string ans = "";
    for(int i=0;i<len;i++) ans += '$'; //dummy values
    int index = len-1;

    int i = n, j = m;
    while(i>0 && j>0){
        if(text1[i-1]==text2[j-1]){
            ans[index] = text1[i-1];
            index--;
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    cout<<ans<<endl;
}