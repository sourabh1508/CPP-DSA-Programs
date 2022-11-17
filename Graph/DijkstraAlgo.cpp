#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dis(V, INT_MAX);
        dis[S] =0;
        pq.push(make_pair(0,S));
        
        while(!pq.empty()){
            int d = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            vector<pair<int,int>>::iterator it;
            for(auto it: adj[prev]){
                int next = it[0];
                int nextDis = it[1];
                if(dis[next] > dis[prev]+nextDis){
                    dis[next] = dis[prev]+nextDis;
                    pq.push(make_pair(dis[next],next));
                    
                }
            }
        }
        return dis;
    }


int main(){
     int n,m;
    cin>>n>>m;
    vector<vector<int>> adj[n];
    for(int i =0; i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int src;
    cin>>src;
   vector<int> dis;
    dis = dijkstra(n,adj,src);
   for(int i =0; i<dis.size(); i++){
       cout<<dis[i]<<" ";
   }
  return 0;
}