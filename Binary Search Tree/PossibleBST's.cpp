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

vector<Node*> numTrees(int st, int en){
        vector<Node*> trees;
        if(st > en)
        {
            trees.push_back(NULL);
            return trees;
        }
        for(int i=st;i<=en;i++)
        {
            vector<Node*> leftTrees = numTrees(st, i-1);
            vector<Node*> rightTrees = numTrees(i+1, en);
            
            for(int j=0;j<leftTrees.size();j++)
            {
                Node* left = leftTrees[j];
                for(int k=0;k<rightTrees.size();k++)
                {
                    Node* right = rightTrees[k];
                    Node* node = new Node(i);
                    node->left = left;
                    node->right = right;
                    trees.push_back(node);
                }
            }
        }
    return trees;
}

void preorder(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<Node*> Trees = numTrees(1, 2);
    for(int i=0;i<Trees.size();i++)
    {
        preorder(Trees[i]);
        cout<<endl;
    }
    return 0;
}