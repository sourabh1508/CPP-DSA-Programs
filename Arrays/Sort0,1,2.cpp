#include<bits/stdc++.h>
using namespace std;

    //Optimal Approach [Time - o(n), Space - O(1)]
    vector<int> sort012(vector<int> v, int n)
    {
        vector<int> arr = v;
        int low = 0;
        int mid = 0;
        int high = n-1;
        
        while(mid<=high){
            if(arr[mid] == 0) swap(arr[mid++], arr[low++]);
            else if(arr[mid] == 1) mid++;
            else if(arr[mid] == 2) swap(arr[mid], arr[high--]);
        }
        return arr;
    }

    int main(){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> v3 = sort012(arr, n);
        for(int i=0;i<n;i++) cout<<v3[i]<<" ";
        cout<<endl;
    }