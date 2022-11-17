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
    
    int widthOfBinaryTree(Node* root) {
        if(root==NULL) return 0;
        int ans = 0;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                Node* node = q.front().first;
                long cur_id = q.front().second - mini;
                q.pop();
                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;
                
                if(node->left!=NULL) q.push({node->left, 2*cur_id+1});
                if(node->right!=NULL) q.push({node->right, 2*cur_id+2});
            }
            ans = max(ans, last-first+1);
        }
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
    cout<<widthOfBinaryTree(root);
    }