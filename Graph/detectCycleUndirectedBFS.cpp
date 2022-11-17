#include<bits/stdc++.h>
using namespace std;

bool checkCycle(int start, vector<int> &vis, vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({start,-1});
        vis[start] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[node]){
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if(it!=parent)
                    return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i, vis, adj))
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