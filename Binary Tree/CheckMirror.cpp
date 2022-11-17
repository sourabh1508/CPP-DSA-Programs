#include<bits/stdc++.h>
using namespace std;

int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int, stack<int>> mp;
        
        for(int i = 0; i < 2*e; i += 2) {
            mp[A[i]].push(A[i+1]);
        }
                
        for(int i = 0; i < 2*e; i += 2) {
            if(mp[B[i]].top() != B[i+1])
                return 0;
            mp[B[i]].pop();
        }
                
        return 1;
}

int main()
{
    int n, e;
    cin>>n>>e;
    int A[] = {1, 2, 1, 3};  
    int B[] = {1, 3, 1, 2};
    
    cout<<checkMirrorTree(n, e, A, B)<<endl;
    return 0;
}