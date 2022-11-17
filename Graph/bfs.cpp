#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<int> vis(V, 0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                queue<int> q;
                vis[i] = 1;
                q.push(i);
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    
                    for(auto it: adj[node]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                            
                        }
                    }
                }
            }
        }
        return bfs;
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
    res = bfsOfGraph(n, adj);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    } 
    return 0;
}