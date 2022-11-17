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

bool isIsomorphic(node* root1, node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    if(root1==NULL || root2==NULL)
        return false;
    if(root1->data!=root2->data)
        return false;
    
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) || 
            (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}

int main()
{
    struct node* root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    struct node* root2 = new node(1);
    root2->left = new node(3);
    root2->right = new node(2);

    cout<<isIsomorphic(root1, root2);
    return 0;
}