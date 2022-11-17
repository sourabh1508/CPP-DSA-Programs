#include<bits/stdc++.h>
using namespace std;

//T.C - O(N*N), S.C - O(N*N)
void rotate1(vector<vector<int>> mat, int n){
    vector<vector<int>> ans(n, vector<int> (n));

    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            ans[j][i] = mat[n-i-1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

//T.C - O(N*N), S.C - O(1)
void rotate2(vector<vector<int>> &mat, int n){
    //Transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    //Reverse every Row
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(), mat[i].end());
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int n,m;
    cin>>n;

    vector<vector<int>> mat(n, vector<int> (n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    rotate1(mat, n);
    cout<<endl;
    rotate2(mat, n);
}