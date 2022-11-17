    #include<bits/stdc++.h>
    using namespace std;
    
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dis(V, 1e8);
        
        dis[S] = 0;
        
        for(int i=0;i<V-1;i++){
            for(auto it: adj){
                if(dis[it[0]] + it[2] < dis[it[1]]) 
                    dis[it[1]] = it[2] + dis[it[0]]; 
            }
        }

        bool fl = 0;
        for(auto it: adj){
            if(dis[it[0]] + it[2] < dis[it[1]]) {
                fl = 1;
                cout<<"Negative Cycle"<<endl;
                break;
            }
        }   
        if(fl==0) 
            return dis;
    }

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj;
    for(int i=0;i<m;i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(wt);
        adj.push_back(temp);
    }

    int src = 0;
    vector<int> dis = bellman_ford(n, adj, src);

    for(int i=0;i<dis.size();i++) cout<<dis[i]<<" ";
    return 0;
}