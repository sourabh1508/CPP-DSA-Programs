#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val){
    if(root == NULL)
        return new Node(val);

    if(root->data == val)
        return root;
    
    if(val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    
    return root;
}

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL)
        return NULL;
    if(root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);
    if(root->data < n2 && root->data < n2)
        return LCA(root->right, n1, n2);
    
    return root;
}

int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    Node* lca = LCA(root, 1, 2);
    cout<<lca->data<<endl;
    return 0;
}