#include<bits/stdc++.h>
using namespace std;

vector<int> Wave(vector<vector<int>> mat, int n, int m){
    vector<int> v;
    bool fl = 0;
    for(int c=0;c<m;c++){
        for(int r=0;r<n;r++){
            if(fl == 0){
                v.push_back(mat[r][c]);
                if(r==n-1) fl = 1;
            } 
            else{
                v.push_back(mat[n-r-1][c]);
                if(r == n-1) fl = 0;
            }   
        }
    }
    return v;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> mat(n, vector<int> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<int> v = Wave(mat, n, m);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}