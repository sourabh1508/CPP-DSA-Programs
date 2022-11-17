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

bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
    if(root == NULL)
        return 1;
    if(min!=NULL && min->data >= root->data)
        return 0;
    if(max!=NULL && max->data <= root->data)
        return 0;
        
    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
        
    return (leftValid and rightValid);
}

int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    cout<<isBST(root1, NULL, NULL);
    return 0;
}