#include<bits/stdc++.h>
using namespace std;

//Memoization
bool memo(int i, int target, int arr[], vector<vector<int>> &dp){
    if(target==0) return true;
    if(i==0) return (arr[0]==target);

    if(dp[i][target] != -1) return dp[i][target];

    bool notTake = memo(i-1, target, arr, dp);
    bool take = false;
    if(arr[i]<=target) take = memo(i-1, target-arr[i], arr, dp);

    return dp[i][target] = notTake || take;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s = 0;
    for(int i=0;i<n;i++) s += arr[i];
    if(s%2==1){ 
        cout<< false;
        return 0;
    }
    vector<vector<int>> dp(n+1, vector<int> (s/2 + 1, -1));
    cout<<memo(n-1, s/2, arr, dp)<<endl;

}