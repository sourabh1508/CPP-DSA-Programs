#include<iostream>
using namespace std;

bool checkPalindrome(int i, string s){
    if(i>=s.length()/2)
        return true;
    if(s[i]!=s[s.length()-i-1])
        return false;
    return checkPalindrome(i+1, s);
}

int main(){
    string s;
    cin>>s;
    cout<<checkPalindrome(0, s);
}