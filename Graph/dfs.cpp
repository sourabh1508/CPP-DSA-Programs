#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs){
        dfs.push_back(node);
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                DFS(it, vis, adj, dfs);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs;
        vector<int> vis(V, 0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                DFS(i, vis, adj, dfs);
            }
        }
        return dfs;
    }

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> res;
    res = dfsOfGraph(n, adj);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    } 
    return 0;
}