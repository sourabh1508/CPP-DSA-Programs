#include<bits/stdc++.h>
using namespace std;

int memo(int ind1, int ind2, int ind3, string &text1, string &text2, string &text3, vector<vector<vector<int>>> &dp){
    if(ind1<0 || ind2<0 || ind3<0) return 0;
    if(dp[ind1][ind2][ind3] != -1) return dp[ind1][ind2][ind3];
    
    if(text1[ind1] == text2[ind2] && text3[ind3] == text2[ind2]) 
        return dp[ind1][ind2][ind3] = 1 + memo(ind1-1, ind2-1, ind3-1, text1, text2, text3, dp);
    
    int a = memo(ind1-1, ind2, ind3, text1, text2, text3, dp); 
    int b = memo(ind1, ind2-1, ind3, text1, text2, text3, dp);
    int c = memo(ind1, ind2, ind3-1, text1, text2, text3, dp);
    int d = memo(ind1-1, ind2-1, ind3, text1, text2, text3, dp);
    int e = memo(ind1-1, ind2, ind3-1, text1, text2, text3, dp);
    int f = memo(ind1, ind2-1, ind3-1, text1, text2, text3, dp);
    
    return dp[ind1][ind2][ind3] = 0 + max(max(a, b), max(max(c, d), max(e,f)));
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1, vector<vector<int>> (n2, vector<int> (n3, -1)));
    return memo(n1-1, n2-1, n3-1, A, B, C, dp); 
}

int main(){
    string A, B, C;
    cin>>A>>B>>C;
    int n1, n2, n3;
    n1 = A.size();
    n2 = B.size();
    n3 = C.size();

    vector<vector<vector<int>>> dp(n1, vector<vector<int>> (n2, vector<int> (n3, -1)));
    cout<<memo(n1-1, n2-1, n3-1, A, B, C, dp); 

}