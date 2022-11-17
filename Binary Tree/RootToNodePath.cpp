#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
      data = val;
      left = NULL;
      right = NULL;
  }  
};

bool RootToNodePathUtil(Node* root, int x, vector<int> &ans){
    if(root == NULL) return false;
    ans.push_back(root->data);
    if(x==root->data) return true;

    if(RootToNodePathUtil(root->left, x, ans) || RootToNodePathUtil(root->right, x, ans)) return true;

    ans.pop_back(); //BackTracking
    return false;
}

vector<int> RootToNodePath(Node* root, int x){
    vector<int> ans;
    if(root==NULL) return ans;
    RootToNodePathUtil(root, x, ans);
    return ans;
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int x = 5;
    vector<int> ans = RootToNodePath(root, x);
    for(auto it: ans) cout<<it<<" ";
    cout<<endl;
    return 0;
}