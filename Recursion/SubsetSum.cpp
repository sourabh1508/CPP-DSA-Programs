#include<bits/stdc++.h>
using namespace std;

void findSum(int i, int s, vector<int> &arr, vector<int> &ds){
        if(i==arr.size()){
            ds.push_back(s);
            return;
        }
        
        findSum(i+1, s+arr[i], arr, ds);
           
        findSum(i+1, s, arr, ds);
    }
    
int main(){
    vector<int> v = {2,3};

    vector<int> ans;
    findSum(0, 0, v, ans);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}