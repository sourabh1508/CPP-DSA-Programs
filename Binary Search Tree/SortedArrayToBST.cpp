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

Node* ArrToBST(int arr[], int st, int en){
    if(st > en)
        return NULL;
    int mid = (st+en)/2;
    Node* root = new Node(arr[mid]);

    root->left = ArrToBST(arr, st, mid-1);
    root->right = ArrToBST(arr, mid+1, en);

    return root;
}

void preorderPrint(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    Node* root = ArrToBST(arr, 0, 4);
    preorderPrint(root);
    return 0;
}