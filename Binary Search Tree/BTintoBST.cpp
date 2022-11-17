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

void inorder(Node* root, vector<int> &v){
        if(root==NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
}

Node* Util(vector<int> v, int st, int en){
        
        if(st > en)
            return NULL;
        int mid = (st+en)/2;
        Node* newRoot = new Node(v[mid]);
        newRoot->left = Util(v, st, mid-1);
        newRoot->right = Util(v, mid+1, en);
        
        return newRoot;
}
    
Node *binaryTreeToBST (Node *root)
{
        vector<int> v;
        inorder(root, v);
        sort(v.begin(), v.end());
        int n = v.size();
        Node* newRoot = Util(v, 0, n-1);
        return newRoot;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    vector<int> v1,v2;
    inorder(root, v1);
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    Node* newRoot = binaryTreeToBST(root);
    inorder(newRoot, v2);
    for(int i=0;i<v2.size();i++)
        cout<<v2[i]<<" ";
    cout<<endl;
    return 0; 
}
