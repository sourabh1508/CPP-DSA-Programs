    #include<bits/stdc++.h>
    using namespace std;
    
    //Memoization
    int robberMemo(int ind, vector<int> &nums, vector<int> &dp){
        if(ind==0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int pick = nums[ind] + robberMemo(ind-2, nums, dp);
        int nonpick = 0 + robberMemo(ind-1, nums, dp);
        
        return dp[ind] = max(pick, nonpick);
    }

    //Tabulation
    int robberTab(vector<int> &nums, vector<int> &dp){
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int nonpick = 0 + dp[i-1]; 
            dp[i] = max(pick, nonpick);
        }
        return dp[nums.size()-1];
    }
    
    //Space Optimized
    int robberOp(vector<int> &nums){
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<nums.size();i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int nonpick = 0 + prev; 
            int cur = max(pick, nonpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

int main(){ //Finding the maximum sum of a subsequence with no adjacent values
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    vector<int> dp(nums.size(), -1);
    cout<<robberMemo(nums.size()-1, nums, dp)<<endl;
    vector<int> dp1(nums.size(), -1);
    cout<<robberTab(nums, dp1)<<endl;
    cout<<robberOp(nums)<<endl;
}