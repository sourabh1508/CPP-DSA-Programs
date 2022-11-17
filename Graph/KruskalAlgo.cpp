#include<bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int v; 
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) {
    return a.wt < b.wt; 
}

int findParent(int node, vector<int> &parent){
    if(node==parent[node])
        return node;
    return parent[node] = findParent(parent[node], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rankk){
    u = findParent(u, parent);
	v = findParent(v, parent);
	
	if(rankk[u]>rankk[v]) parent[v] = u;
	else if(rankk[v]>rankk[u]) parent[u] = v;
	else{
	    parent[v] = u;
	    rankk[u]++;
	}
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<node> edges;
    edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,3));
	edges.push_back(node(0,2,1));
	

    sort(edges.begin(), edges.end(), comp);
    
    vector<int> parent(n);
    for(int i=0;i<n;i++) parent[i] = i;

    vector<int> rank(n, 0);

    int cost=0;
    vector<pair<int,int>> mst;
    for(auto it: edges){
        if(findParent(it.v, parent) != findParent(it.u, parent)){
            cost += it.wt;
            mst.push_back({it.u, it.v});
            Union(it.u, it.v, parent, rank);
        }
    }
    cout<<cost<<endl;
    for(auto it: mst){
        cout<<it.first<<"-"<<it.second<<endl;
    }

}