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

vector<int> zigZagTraversal(node* root)
    {
        vector<int> res;
    	stack<node*> s1, s2;
        node* temp;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                temp = s1.top();
                res.push_back(temp->data);
                s1.pop();
                
                if(temp->left!=NULL){
                    s2.push(temp->left);
                }
                if(temp->right!=NULL){
                    s2.push(temp->right);
                }
            }
            while(!s2.empty()){
                temp = s2.top();
                res.push_back(temp->data);
                s2.pop();
                
                if(temp->right!=NULL){
                    s1.push(temp->right);
                }
                if(temp->left!=NULL){
                    s1.push(temp->left);
                }
            }
        }
        return res;
    }

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    vector<int> ans = zigZagTraversal(root);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}