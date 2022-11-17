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

vector<int> morrisTraversal(Node* root){
    vector<int> ans;
    Node* cur = root;
    while(cur!=NULL){
        if(cur->left == NULL){
            ans.push_back(cur->data);
            cur = cur->right;
        }
        else{
            Node* prev = cur->left;
            while(prev->right != NULL && prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == NULL){   //For Preorder, add the node to vector before moving to left.
                prev->right = cur;    //adding thread
                cur = cur->left;
            }
            else{
                prev->right = NULL; //removing thread
                ans.push_back(cur->data);  //For Inorder, add the node to vector after moving to left.
                cur = cur->right;
            }
        }
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
    vector<int> ans = morrisTraversal(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}