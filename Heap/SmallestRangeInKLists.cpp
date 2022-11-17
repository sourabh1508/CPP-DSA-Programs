#include<bits/stdc++.h>
using namespace std;

class element {
    public:
    int val;
    int ind;
    int row;
    int arrsize;
    
    element(int v, int i, int r, int as){
        val = v;
        ind = i;
        row = r;
        arrsize = as;
    }
};

struct compare{
    bool operator()(element a, element b){
        return a.val > b.val;
    }
};

vector<int> SmallestRange(vector<vector<int>> &arr){

    int mn = INT_MAX, mx = INT_MIN, range = INT_MAX;
    priority_queue<element, vector<element>, compare> pq;

    int k = arr.size();
    int low, high;

    for(int i=0;i<k;i++){
        element temp(arr[i][0], 0, i, arr[i].size());
        pq.push(temp);
        mn = min(mn, arr[i][0]);
        mx = max(mx, arr[i][0]);
    }

    while(!pq.empty()){
        element current = pq.top();
        pq.pop();
        int maybeminimum = current.val;

        if(range > mx - maybeminimum){
            mn = maybeminimum;
            range = mx - mn;
            low = mn;
            high = mx;
        }
        if(current.ind == current.arrsize-1)
            break;
        
        current.ind += 1;
        element temp(arr[current.row][current.ind], current.ind, current.row, arr[current.row].size());
        pq.push(temp);
    }
    vector<int> v{low, high};
    return v;
}

int main(){
    vector<vector<int>> arr{{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    
    vector<int> ans = SmallestRange(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

