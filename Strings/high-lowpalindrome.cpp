#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    
    map<char, int> m;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }
    for(int i=0;i<m.size();i++){
        cout<<s[i]<<to_string(m[s[i]]);
    }
    
    return 0;
}
