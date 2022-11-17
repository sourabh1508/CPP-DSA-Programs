#include<bits/stdc++.h>
using namespace std;

void findCombinations(int i, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds){
        
            if(target==0){
                ans.push_back(ds);
                return;
            }
            if(i == candidates.size()) return;
        
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            findCombinations(i, target - candidates[i], candidates, ans, ds);
            ds.pop_back();
        }
        findCombinations(i+1, target, candidates, ans, ds);
    }
    
int main(){
    vector<int> v = {2,3,6,7};
    int target = 7;

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