#include<bits/stdc++.h>
using namespace std;
    
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it, vis, adj,st);
        }
        st.push(node);
    }
    
    void revdfs(int node, vector<int> &vis, vector<int> transpose[]){
        vis[node] = 1;
        cout<<node<<" ";
        for(auto it: transpose[node]){
            if(!vis[it]) revdfs(it, vis, transpose);
        }
    }
    
    void kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i, vis, adj, st);
        }
        
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                transpose[it].push_back(i);       
            }
        }
        
        while(!st.empty()){
            int temp = st.top();
            st.pop();
            if(!vis[temp]){
                revdfs(temp, vis, transpose);
                cout<<endl;
            }
        }
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

    kosaraju(n, adj);
    return 0;
}