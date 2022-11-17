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

void inorderPredecessor(Node* root, Node* &pre, int val){
    
    while(root!=NULL){
        if(val < root->data){
            root = root->left;
        }
        else{
            pre = root;
            root = root->right;
        }
    }
}

void inorderSuccessor(Node* root, Node* &suc, int val){
    while(root!=NULL){
        if(val >= root->data){
            root = root->right;
        }
        else{
            suc = root;
            root = root->left;
        }
    }
}


int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    Node* pre = NULL;
    Node* suc = NULL;
    inorderSuccessor(root, suc, 5);
    inorderPredecessor(root, pre, 5);
    // if(pre!=NULL)
    //     cout<<pre->data<<" ";
    // else
    //     cout<<-1;

    if(suc!=NULL)
        cout<<suc->data<<" "<<endl;
    else    
        cout<<-1; 
    return 0;
}