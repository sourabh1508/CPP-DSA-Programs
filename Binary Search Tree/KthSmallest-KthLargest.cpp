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

    int kthSmallest(Node* root, int &k) {
        if(root==NULL) return -1;
        int left = kthSmallest(root->left, k);
        if(left != -1)
            return left;
        k--;
        if(k==0){  
            return root->data;
        }
        
        int right = kthSmallest(root->right, k);
        if(right != -1)
            return right;
        return -1;
    }

    int kthLargest(Node* root, int &k) {
        if(root==NULL) return -1;
        int right = kthLargest(root->right, k);
        if(right != -1)
            return right;
        k--;
        if(k==0){  
            return root->data;
        }
        int left = kthLargest(root->left, k);
        if(left != -1)
            return left;
        return -1;
    }

int main(){
    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    int k1=3, k2=3;
    cout<<kthSmallest(root, k1)<<endl;
    cout<<kthLargest(root, k2)<<endl;
    return 0;
}