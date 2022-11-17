#include<bits/stdc++.h>
using namespace std;
    
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    void f(int index, string s, vector<string> &ds, vector<vector<string>> &ans){
        if(index==s.length()){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s, index, i)){
                ds.push_back(s.substr(index, i-index+1));
                f(i+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }

    int main(){
    string s = "aabb";
    vector<vector<string>> ans;
    vector<string> ds;
    f(0, s, ds, ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" "; 
        }
        cout<<endl;
    }
}