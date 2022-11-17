#include<bits/stdc++.h>
using namespace std;
    
    void TOPOSORT(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
	    vis[node] = 1;
	    
	    for(auto it: adj[node]){
	        if(!vis[it]){
	            TOPOSORT(it, adj, vis, st);
	        }
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> topo;
	    vector<int> vis(V, 0);
	    stack<int> st;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            TOPOSORT(i, adj, vis, st);
	        }
	    }
	    while(!st.empty()){
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo; 
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

    vector<int> topo = topoSort(n, adj);
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }
    return 0;
}