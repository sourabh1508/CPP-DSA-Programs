    #include<bits/stdc++.h>
    using namespace std;
    
    void RatInAMaze(int i, int j, vector<vector<int>> &m, int n,
    vector<string> &ans, string s, vector<vector<int>> &vis, int di[], int dj[]){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        string dir = "DLRU";
        for(int k=0;k<4;k++){
            int nexti = i+di[k];
            int nextj = j+dj[k];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && m[nexti][nextj]==1){
                vis[i][j]= 1;
                RatInAMaze(nexti, nextj, m, n, ans, s+dir[k], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0]==1)
            RatInAMaze(0, 0, m, n, ans, "", vis, di, dj);
        return ans;
    }

    int main(){
        int n;
        cin>>n;

        vector<vector<int>> m(n, vector<int> (n, 0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>m[i][j];
            }
        }

        vector<string> ans;
        ans = findPath(m, n);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }