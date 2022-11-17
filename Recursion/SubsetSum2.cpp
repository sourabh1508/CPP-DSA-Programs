#include<bits/stdc++.h>
using namespace std;

    void findSubsets(int index, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
        
        ans.push_back(ds);
            
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            findSubsets(i+1, arr, ds, ans);
            ds.pop_back();    
        }
        
    }

int main(){
    vector<int> v = {1,2,2};
    sort(v.begin(), v.end());
    vector<int> ds;
    vector<vector<int>> ans;
    findSubsets(0, v, ds, ans);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" "; 
        }
        cout<<endl;
    }
}