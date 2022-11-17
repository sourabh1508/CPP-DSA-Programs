#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, bool graph[101][101], int color[], int m, int n, int col){
    for(int k=0;k<n;k++){
        if(k!=node && graph[k][node]==1 && color[k]==col) return false;
    }
    return true;
}

bool solve(int node, bool graph[101][101], int color[], int m, int n){
    if(node==n)
        return true;
        
    for(int i=1;i<=m;i++){
        if(isSafe(node, graph, color, m, n, i)){
            color[node] = i;
            if(solve(node+1, graph, color, m, n)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n] = {0};
    if(solve(0, graph, color, m, n)==true)
        return true;
    return false;
}

int main(){
    int m, n, e;
    cin>>m>>n>>e;
    bool graph[101][101];
    for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
}