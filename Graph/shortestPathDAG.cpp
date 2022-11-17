#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

void toposort(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st){
    vis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it.first])
            toposort(it.first, adj, vis, st);
    }
    st.push(node);
}

vector<int> ShortestDistance(int V, vector<pair<int,int>> adj[], int src){
    stack<int> st;
    vector<int> dist(V, INF);
    vector<int> vis(V,0);

    for(int i=0;i<V;i++){
        if(!vis[i])
            toposort(i, adj, vis, st);
    }

    dist[src] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dist[node]!=INF){
            for(auto it: adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }
    return dist;
    
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v, wt});
    }

    int src;
    cin>>src;

    vector<int> dist;
    dist = ShortestDistance(n, adj, src);
    for(int i=0;i<dist.size();i++){
        if(dist[i]==INF)   cout<<"INF"<<" ";
        else cout<<dist[i]<<" ";
    }
    return 0;
}