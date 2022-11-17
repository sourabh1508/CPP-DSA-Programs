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

Node* BuildBST(vector<int> v, int st, int en){
        if(st > en)
            return NULL;
        int mid = (st+en)/2;
        Node* newRoot = new Node(v[mid]);
        newRoot->left = BuildBST(v, st, mid-1);
        newRoot->right = BuildBST(v, mid+1, en);
        
        return newRoot;
}

Node* Merge2BST(Node* root1, Node* root2, int n1, int n2){
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);
    v1.insert( v1.end(), v2.begin(), v2.end());
    sort(v1.begin(), v1.end());
    return BuildBST(v1, 0, v1.size()-1);
    
}

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(7);

    Node* root2 = new Node(5);
    root2->left = new Node(7);
    root2->right = new Node(9);
    
    Node* newRoot = Merge2BST(root1, root2, 3, 3);
    vector<int> v;
    inorder(newRoot, v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}