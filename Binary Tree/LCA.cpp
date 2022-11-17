#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool getPath(node* root, int key, vector<int> &path)
{
    if(root==NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if(root->data == key)
    {
        return true;
    }   

    if(getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }   
    int pc;
    for(pc=0;pc<path1.size() && path2.size(); pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
    }   
    return path1[pc-1];
}

node* lca2(node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
            return NULL;
            
        if(root->data==n1 || root->data == n2)
            return root;
        
        node* leftLCA = lca2(root->left, n1, n2);
        node* rightLCA = lca2(root->right, n1, n2);
        
        if(leftLCA!=NULL && rightLCA!=NULL)
            return root;
        
        if(leftLCA!=NULL)
            return leftLCA;
        
        if(rightLCA!=NULL)
            return rightLCA;
    }

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    int lca = LCA(root, 5, 7);
    if(lca==-1)
    {
        cout<<"LCA doesn't exist"<<endl;
    }
    else
    {
        cout<<"LCA: "<<lca<<endl;
    }

    node* LCA2 = lca2(root, 6, 7);
    cout<<"LCA: "<<LCA2->data<<endl;

    return 0;
}