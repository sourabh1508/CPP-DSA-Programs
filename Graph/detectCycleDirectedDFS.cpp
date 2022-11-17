#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> adj[], vector<int> &dfsvis, vector<int> &vis){
    vis[node] = 1;
    dfsvis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(checkCycle(it, adj, dfsvis, vis)) return true;
        }
        else if(vis[it] && dfsvis[it]) return true;
    }
    dfsvis[node] = 0;
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    vector<int> vis(V, 0);
    vector<int> dfsvis(V, 0);

    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(checkCycle(i, adj, dfsvis, vis))
                return true;
        }
    }
    return false;
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

    cout<<isCycle(n, adj);
    return 0;
}