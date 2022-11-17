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

void levelOrder(struct node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        if(curr!=NULL){
            cout<<curr->data<<" ";
            if(curr->left!=NULL){
            q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

node* mirror(node* root){
    if(root==NULL){
        return NULL;
    }
    swap(root->left, root->right);

    if (root->left!=NULL)
        mirror(root->left);
    if (root->right!=NULL);
        mirror(root->right);

    return root;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    levelOrder(root);
    cout<<endl;
    levelOrder(mirror(root));
    cout<<endl;
    return 0;
}