#include<bits/stdc++.h>
using namespace std;

    //BruteForce Approach [Time - O(nlogn), Space - O(1)]
    int f1(int arr[], int n){
        sort(arr, arr+n);
        for(int i=0;i<n;i++){
            if(arr[i] == arr[i+1]) return arr[i];
        }
    }

    //Better Approach [Time - O(n), Space - O(n)]
    int f2(int arr[], int n){
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            if(mp[arr[i]]>1) return arr[i];
        }
    }

    //Best Approach [Time - O(n), Space - O(1)] 
    int findDuplicate(int nums[]) {
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        while(fast!=slow);
        
        fast = nums[0];
        while(slow!=fast){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<f1(arr, n)<<endl;
    cout<<f2(arr, n)<<endl;
    cout<<findDuplicate(arr)<<endl;
}