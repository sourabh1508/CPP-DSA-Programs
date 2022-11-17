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

int minBST(Node* root){
    if(root==NULL)
        return -1;
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}

int maxBST(Node* root){
    if(root==NULL)
        return -1;
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}

int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    cout<<"Minimum: "<<minBST(root)<<endl;
    cout<<"Maximum: "<<maxBST(root)<<endl;
    return 0;
}