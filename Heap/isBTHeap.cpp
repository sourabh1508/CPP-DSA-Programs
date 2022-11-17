#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node* left;
  struct node* right;

  node(int val){
      data = val;
      left = NULL;
      right = NULL;
  }  
};
    
    int count(node* root){
        if(root==NULL) return 0;
        return 1+count(root->left)+count(root->right); 
    }
    
    bool isCBT(node* root, int i, int c){
        if(root == NULL) return true;
        if(i>c) return false;
        return isCBT(root->left, 2*i+1, c) && isCBT(root->right, 2*i+2, c);
    }
    
    bool isMaxHeap(node* root){
        if(root->left == NULL && root->right == NULL) return true;
        else if(root->right == NULL) return root->data > root->left->data;
        return root->data > root->left->data && root->data > root->right->data
        && isMaxHeap(root->left) && isMaxHeap(root->right);
    }
  
    bool isHeap(struct node* root) {
        int c = count(root);
        return isCBT(root, 0, c) && isMaxHeap(root); 
    }


int main(){
    struct node* root = new node(3);
    root->left = new node(2);
    root->right = new node(1);
    cout<<isHeap(root);
}