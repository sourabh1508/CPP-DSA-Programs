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

void levelorder(struct node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
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
        }
        
    }
}

int sumAtKthLevel(node* root, int k){
    queue<node*> q;
    int sum = 0, lvl = 0;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        if(curr!=NULL){
            if(lvl==k){
                sum += curr->data;
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
            
        }
        else if(!q.empty()){
            q.push(NULL);
            lvl++;
        }
    }
    return sum;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    levelorder(root);
    cout<<endl;
    cout<<sumAtKthLevel(root, 1);
    cout<<endl;
    return 0;
}