#include<bits/stdc++.h>
using namespace std;

int SpacOp(string &text1, string &text2, int n, int m, vector<int> &prev, vector<int> &cur){
    for(int j=0;j<=m;j++)prev[j] = 0;
    
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
    string s, t;
    cin>>s>>t;
    
    int n = s.size();
    int m = t.size();
    
    vector<int> prev(m+1, 0), cur(m+1, 0);
    int lcs = SpacOp(s, t, m, n, prev, cur);
    cout<<"Shortest Common Supersequence"<<endl;
    cout<<"Length: "<<m + n - lcs<<endl;

    string ans = "";
    int i=m, j=n;

    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans += s[i-1];
            i--; j--;
        }
        else if(prev[j]>cur[j-1]){
            ans += s[i-1];
            i--;
        }
        else{
            ans += t[j-1];
            j--;
        }
    }

    while(i>0){
        ans += s[i-1];
        i--;
    }
    while(j>0){
        ans += t[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout<<"String: "<<ans<<endl;
}