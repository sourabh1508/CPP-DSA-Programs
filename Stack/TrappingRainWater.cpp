#include<bits/stdc++.h>
using namespace std;
    
    int trap(int height[]) {
        stack<int> st;
        int n = 12;
        int left[n];
        int right[n];
        
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<height[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = height[i];
            }
            else{
                left[i] = st.top();
            }
            if(st.empty() || (!st.empty() && height[i]>st.top())){
                st.push(height[i]);
            }
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<height[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = height[i];
            }
            else{
                right[i] = st.top();
            }
            if(st.empty() || (!st.empty() && height[i]>st.top())){
                st.push(height[i]);
            }
        }
        int rainStored = 0;
        for(int i=0;i<n;i++){
           
            rainStored += (min(left[i], right[i]) - height[i]);
        }
        return rainStored;
        
    }

int main(){
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height);
}