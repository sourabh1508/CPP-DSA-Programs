#include<bits/stdc++.h>
using namespace std;
    
    int spanningTree(int N, vector<pair<int,int>> adj[])
    {
        int key[N], parent[N];
        bool MST[N];
        
        for(int i=0;i<N;i++){
            key[i] = INT_MAX;
            parent[i] = -1;
            MST[i] = false;
        }
        key[0] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            
            MST[u] = true;
            
            for(auto it: adj[u]){
                int node = it.first;
                int wt = it.second;
                if(MST[node]==false && key[node] > wt){
                    key[node] = wt;
                    parent[node] = u;
                    pq.push({key[node], node});
;               }
            }
        }
        int ans = 0;
        for(int i=0;i<N;i++) ans += key[i];
        return ans;
    }

int main(){
    int n, m;
    cin>>n>>m;

    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});\
        adj[v].push_back({u,wt});
    }
    cout<<spanningTree(n, adj);
    return 0;
}