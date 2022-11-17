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
    
    bool isLeaf(Node* root){
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
     
    void leftBoundary(Node* root, vector<int> &ans){
        Node* curr = root->left;
        while(curr!=NULL){
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left!=NULL) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void leafNodes(Node* root, vector<int> &ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
        }
        if(root->left!=NULL) leafNodes(root->left, ans);
        if(root->right!=NULL) leafNodes(root->right, ans);
    }
    
    void rightBoundary(Node* root, vector<int> &ans){
        vector<int> temp;
        Node* curr = root->right;
        while(curr!=NULL){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right!=NULL) curr = curr->right;
            else curr = curr->left;
        }
        for(int i=temp.size()-1;i>=0;i--) ans.push_back(temp[i]);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);
        leftBoundary(root, ans);
        leafNodes(root, ans);
        rightBoundary(root, ans);
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
    vector<int> ans = boundary(root);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    }