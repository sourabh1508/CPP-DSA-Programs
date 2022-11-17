#include<bits/stdc++.h>
using namespace std;

int parent[10000];
int rankk[10000];

void makeSet(int n){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        rankk[i] = 0;
    }
}

int findParent(int node){
    if(node==parent[node])
        return node;
    return parent[node] = findParent(parent[node]);
}

void Union(int X, int Y){
    int u = findParent(X);
	int v = findParent(Y);
	
	if(rankk[u]>rankk[v]) parent[v] = u;
	else if(rankk[v]>rankk[u]) parent[u] = v;
	else{
	    parent[v] = u;                                       
	    rankk[u]++;
	}
}

int main(){
    makeSet(10);
    int m;
    cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }

    if(findParent(2) != findParent(3)) cout<<"Different";
    else cout<<"Same"; 

}