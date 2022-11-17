#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> tin, vector<int> low, vector<int> &vis, int timer, vector<int> adj[], vector<int> &arti){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    
    for(auto it: adj[node]){
        if(it==parent) continue;

        if(!vis[it]){
            dfs(it, node, tin, low, vis, timer, adj, arti);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent!=-1) arti[node] = 1;
            child++;
        }
        else{
            low[node] = min(low[node], tin[it]);
        }
    }

    if(parent == -1 && child>1) arti[node] = 1; 
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> tin(n,-1);
    vector<int> low(n,-1);
    vector<int> vis(n,0);
    vector<int> arti(n, 0);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, -1, tin, low, vis, timer, adj, arti);
        }
    }

    for(int i=0;i<n;i++){
        if(arti[i]==1) cout<<i<<" ";
    }

    return 0;
}