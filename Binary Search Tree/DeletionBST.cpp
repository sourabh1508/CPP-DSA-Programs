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

void inorder(Node* root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* deleteInBST(Node* root, int val){
    if(root == NULL)
        return NULL;
    
    if(val < root->data)
        root->left = deleteInBST(root->left, val);
    else if(val > root->data)
        root->right = deleteInBST(root->right, val);
    else{
        Node* temp;
        if(!root->left && !root->right) return NULL;
        else if(root->left == NULL || root->right == NULL){
            return root->left ? root->left : root->right;
        }
        else{
            temp = root->left;                        
            while(temp->right != NULL) temp = temp->right;

            root->data = temp->data;
            root->right = deleteInBST(root->right, val);
        }
    }
    return root;
}

int main(){
    Node* root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 1);
    insertBST(root, 2);
    insertBST(root, 3);
    insertBST(root, 5);
    insertBST(root, 6);
    inorder(root);
    cout<<endl;
    deleteInBST(root, 4);
    inorder(root);
    return 0;
}
