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

node* kthancestor(node* root, int node, int &k){
    if(root==NULL)
        return 0;
    if(root->data == node || kthancestor(root->left, node, k) || kthancestor(root->right, node, k))
    {
        if(k>0)
            k--;
        
        else if(k==0){
            cout<<root->data;
            return NULL;
        }
        return root;
    }
}

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int node = 7;
    int k = 2;
    struct node* res;
    res = kthancestor(root, node, k);
    return 0;
}