#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

   Node *prev = NULL;
   Node* bToDLL(Node* root){
       if(root==NULL)   
            return root;
       Node *head = bToDLL(root->left);
       if(prev==NULL)   
            head = root;
       else {
           root->left = prev;
           prev->right = root;
       }
       prev = root;
       bToDLL(root->right);
       return head;
   }

void inorder(Node* root){
    if(root==NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    inorder(root);
    cout<<endl;
    Node* newRoot = bToDLL(root);
    inorder(newRoot);
    cout<<endl;   
    return 0;
}