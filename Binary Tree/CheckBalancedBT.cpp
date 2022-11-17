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

int check(node* root){
    if(root == NULL) return 0;
    int l = check(root->left);
    int r = check(root->right);
    if(l == -1 || r == -1) return -1;
    if(abs(l-r)>1) return -1;
    return max(l,r)+1;
}

bool checkBalanced(node* root){
    if(root == NULL) return true;
    if(check(root) != -1) return true;
    return false;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    //root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    cout<<checkBalanced(root);
}