    #include<bits/stdc++.h>
    using namespace std;
    
    void findPerms(int ind, vector<vector<int>> &ans, vector<int> &nums){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind], nums[i]);
            findPerms(ind+1,ans, nums);
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPerms(0, ans, nums);
        return ans;
    }

    int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = permute(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}