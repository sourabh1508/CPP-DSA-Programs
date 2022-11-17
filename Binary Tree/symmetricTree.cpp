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


bool solve(node* l,node* r){
        if(l==NULL || r==NULL) return l==r;
        if(l->data != r->data) return false;
        return solve(l->left, r->right) && solve(l->right, r->left);
    }
    
    bool isSymmetric(node* root) {
        return (root == NULL) || solve(root->left, root->right); 
    }


int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(5);
    root->right->right = new node(4);
    cout<<isSymmetric(root);
    return 0;
}