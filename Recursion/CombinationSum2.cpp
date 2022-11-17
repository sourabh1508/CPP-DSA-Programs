#include<bits/stdc++.h>
using namespace std;

    void findCombinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){   
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<arr.size(); i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findCombinations(i+1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

int main(){
    vector<int> v = {10,1,2,7,6,1,5};
    int target = 8;
    sort(v.begin(), v.end());
    vector<int> ds;
    vector<vector<int>> ans;
    findCombinations(0, target, v, ans, ds);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" "; 
        }
        cout<<endl;
    }
}