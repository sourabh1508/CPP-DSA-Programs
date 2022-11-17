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

bool checkUtil(node* root, int level, int *leaflevel)
    {
        if(root==NULL)
            return true;
        if(root->left==NULL && root->right==NULL)
        {
            if(*leaflevel==0)
            {
                *leaflevel = level;
                return true;
            }
            return (*leaflevel==level);
        }
        return checkUtil(root->left, level+1, leaflevel) && checkUtil(root->right, level+1, leaflevel);
    }
    
    
    bool check(node *root)
    {
        int level = 0;
        int leaflevel = 0;
        return checkUtil(root, level, &leaflevel);
    }

int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<check(root)<<endl;
    return 0;
}