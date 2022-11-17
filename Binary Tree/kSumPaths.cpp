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

void printVector(const vector<int> &v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

void getPath(node* root, vector<int> &path, int k)
{
    if(root==NULL)
        return;
    path.push_back(root->data);
    
    getPath(root->left, path, k);
    getPath(root->right, path, k);

    int sum = 0;
    for(int i=path.size()-1;i>=0;i--)
    {
        sum += path[i];
        if(sum == k)
            printVector(path, i);
    }
    path.pop_back();
}

void kSumPath(node* root, int k)
{
    vector<int> path;
    getPath(root, path, k);
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
    kSumPath(root, 7);
    return 0;
}