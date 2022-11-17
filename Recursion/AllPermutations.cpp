    #include<bits/stdc++.h>
    using namespace std;    
    
    
    void findPerms(vector<int> &ds, vector<int> &arr, int n, vector<vector<int>> &ans, int freq[]){
        if(ds.size()==n){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++){
            if(freq[i]==0){
                ds.push_back(arr[i]);
                freq[i] = 1;
                findPerms(ds, arr, n, ans, freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[arr.size()] = {0};
        findPerms(ds, arr, n, ans, freq);
        return ans;
    }

int main(){
    vector<int> arr = {1, 2, 3};
    int n = 3;
    vector<vector<int>> ans = uniquePerms(arr, n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}