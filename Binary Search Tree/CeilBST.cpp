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

int findCeil(Node* root, int k) {
    int ceil = -1;
    while(root!=NULL){
        if(root->data < k){
           root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

int findFloor(Node* root, int k) {
    int floor = -1;
    while(root!=NULL){
        if(root->data <= k){
            floor = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return floor;
}

int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    cout<<findCeil(root, 5)<<endl;
    cout<<findFloor(root, 5)<<endl;
    return 0;
}