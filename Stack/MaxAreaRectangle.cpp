#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int MAH(vector<int> heights){   
        int n = heights.size();
        
        stack<int> st;
        
        int leftSmall[n];
        int rightSmall[n];
        
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                leftSmall[i] = 0;
            }
            else{
                leftSmall[i] = st.top() + 1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                rightSmall[i] = n - 1;
            }
            else{
                rightSmall[i] = st.top() - 1;
            }
            st.push(i);
        }
        
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx, heights[i] * (rightSmall[i]-leftSmall[i]+1));        
        }
        return mx; 
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> v(m);
        for(int j=0;j<m;j++){
            v[j] = M[0][j];
        }
        int res = MAH(v);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0)
                    v[j] = 0;
                else
                    v[j] = v[j] + M[i][j];
            }
            res = max(res, MAH(v));
        }
        
        return res;
    }

int main(){
    int n, m;
    cin>>n>>m;
    int arr[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<maxArea(arr, n, m);
}