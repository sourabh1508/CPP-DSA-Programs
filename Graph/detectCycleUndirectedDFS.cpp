#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int node, int parent, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[node]){
                if(checkCycle(it, node, vis, adj)) return true;
            }
            else if(it!=parent)
                return true;
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i, -1, vis, adj))
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
        adj[v].push_back(u);
    }

    cout<<isCycle(n, adj);
    return 0;
}
