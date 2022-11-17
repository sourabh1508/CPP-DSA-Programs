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

Node* constructBST(int pre[], int *preidx, int key, int min, int max, int n){
    if(*preidx >= n)
        return NULL;
    
    Node* root = NULL;
    if(key>min && key<max){
        root = new Node(key);
        *preidx += 1;

        if(*preidx < n){
            root->left = constructBST(pre, preidx, pre[*preidx], min, key, n);
        }
        if(*preidx < n){
            root->right = constructBST(pre, preidx, pre[*preidx], key, max, n);
        }
    }
    return root;
}

//Optimized Approach
Node* build(int pre[], int &i, int upper){
    if(i==5 || pre[i] >= upper) return NULL;
    Node* root = new Node(pre[i++]);
    root->left = build(pre, i, root->data);
    root->right = build(pre, i, upper);
    return root;
} 

void PrintPreorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

int main(){
    int pre[] = {10, 2, 1, 13, 11};
    int n=5;
    int preidx = 0;
    Node* root = constructBST(pre, &preidx, pre[0], INT_MIN, INT_MAX, n);
    PrintPreorder(root);
    cout<<endl;
    int i=0;
    Node* root2 = build(pre, i, INT_MAX);
    PrintPreorder(root2);
    cout<<endl;
    return 0;
}