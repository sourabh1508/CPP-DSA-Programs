#include<bits/stdc++.h>
using namespace std;

class element {
    public:
    int val;
    int ind;
    int row;
    
    element(int v, int i, int r){
        val = v;
        ind = i;
        row = r;
    }
};

struct compare{
    bool operator()(element a, element b){
        return a.val > b.val;
    }
};

vector<int> mergeKArrays(int arr[3][3], int K){
    priority_queue<element, vector<element>, compare> pq;

    for(int i=0;i<K;i++){
        element temp(arr[i][0], 0, i);
        pq.push(temp);
    }
    vector<int> ans;

    while(!pq.empty()){
        element current = pq.top();
        pq.pop();
        ans.push_back(current.val);

        if(current.ind > K-1){
            element temp(arr[current.row][current.ind+1], current.ind+1, current.row);
            pq.push(temp);
        }
    }
    return ans;
}

int main(){
    int k=3;
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    
    vector<int> ans = mergeKArrays(arr, k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}