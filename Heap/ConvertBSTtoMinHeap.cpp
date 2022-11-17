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

void inorder(node* root, vector<int> &v){
    if(root == NULL) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void make(node* root, vector<int> v, int &i){
    if(root == NULL) return;
    root->data = v[i++];
    make(root->left, v, i);
    make(root->right, v, i);
}

void ToMinHeap(node* root){
    vector<int> v;
    inorder(root, v);
    int i=0;
    make(root, v, i);
    
}

void print(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main(){
    struct node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);
    print(root);
    cout<<endl;
    ToMinHeap(root);
    print(root);
}