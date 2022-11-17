#include<bits/stdc++.h>
using namespace std;

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


int robber2(vector<int> nums){
    vector<int> temp1, temp2;
    int n=nums.size();
    if(n==1) return nums[0];
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
    }
    return max(robberOp(temp1), robberOp(temp2));
}

int main(){ //Finding the maximum sum of a subsequence with no adjacent values and first and last are adjacent
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<robber2(nums)<<endl;
    
}