#include<bits/stdc++.h>
#include<stack>
using namespace std;

void balpar(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(!st.empty() && s[i]==')' && st.top()=='(' || !st.empty() && s[i]==']' && st.top()=='[' || !st.empty() && s[i]=='}' && st.top()=='{')
        {
            st.pop();
        }
        else
        {
            cout<<"Unbalanced Parenthesis"<<endl;
            return;
        }
    } 
    cout<<"Balanced Parenthesis"<<endl;
}

int main()
{
    string s="{[()]}{}";
    balpar(s);
    return 0;
}
