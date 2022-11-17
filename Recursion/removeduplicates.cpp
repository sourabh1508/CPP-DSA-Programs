#include<iostream>
using namespace std;

string removeduplicates(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch = s[0];
    string ans = removeduplicates(s.substr(1));
    if(ans[0]==ch)
    {
        return ans;
    }
    else
    {
        return (ch+ans);
    } 
}

int main()
{
    string s = "aaavvdfm";
    cout<<removeduplicates(s);
}