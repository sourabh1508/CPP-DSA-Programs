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

int search(int in[], int st, int en, int curr){
    for(int i=st;i<=en;i++)
    {
        if(in[i]==curr)
        {
            return i;
        }
    }
    return -1;
}

//O(n^2)
node* BuildTree(int pre[], int in[], int st, int en){
    if(st>en){
        return NULL;
    }
    static int i = 0;

    node* Node = new node(pre[i++]);

    if(st==en) return Node;

    int pos = search(in, st, en, Node->data);
    Node->left = BuildTree(pre, in, st, pos-1);
    Node->right = BuildTree(pre, in, pos+1, en);

    return Node;
}

void printInorder(node* root){
    if(root==NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

//O(n)
int i=0;
node* buildTree2(int pre[], int in[], int st, int en, unordered_map<int, int> &mp){
    if(st>en){
        return NULL;
    }

    node* Node = new node(pre[i++]);

    if(st==en) return Node;

    int pos = mp[Node->data];
    Node->left = buildTree2(pre, in, st, pos-1, mp);
    Node->right = buildTree2(pre, in, pos+1, en, mp);

    return Node;
}

node* f(int pre[], int in[], int n){
    unordered_map<int, int> mp;

    for(int i=0;i<n;i++){
        mp[in[i]] = i;
    }

    return buildTree2(pre, in, 0, n-1, mp);
}

int main()
{
    int pre[] = {1, 2, 4, 3, 5};
    int in[] = {4, 2, 1, 5, 3};
    //node* root = BuildTree(pre, in, 0, 4);
    node* root = f(pre, in, 5);
    printInorder(root);
    return 0;
}