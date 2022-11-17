#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxPathSumUtil(node* root, int &ans){
    if(root==NULL)
        return 0;
    
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), 
                    max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);
    return max(root->data, max(root->data + left, root->data + right)); 
}

int maxPathSum(node* root){
    if(root == NULL)
        return 0;
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int solve(node* root, int &ans){
        if(root==NULL) return 0;
        
        int lh = max(0, solve(root->left, ans));
        int rh = max(0, solve(root->right, ans));
        
        ans = max(ans, lh+rh+root->data);
        
        return root->data + max(lh,rh);
    }
    
    int maxPathSum2(node* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<maxPathSum(root)<<endl;
    cout<<maxPathSum2(root)<<endl;
    return 0;
}