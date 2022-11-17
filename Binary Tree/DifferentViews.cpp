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

void leftView(struct node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node* curr = q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);    
            }
            if(curr->right!=NULL){
                q.push(curr->right);    
            }
        }    
    }
}

void rightView(struct node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node* curr = q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);    
            }
            if(curr->right!=NULL){
                q.push(curr->right);    
            }
        }    
    }
}

void topView(node *root)
    {
        if(root == NULL) return;
        map<int,int> mp;
        queue<pair<node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            node* Node = it.first;
            int line = it.second;
            
            if(mp.find(line)==mp.end()) mp[line] = Node->data;
            
            if(Node->left) q.push({Node->left,line-1});
            if(Node->right) q.push({Node->right,line+1});
        }
        
        for(auto it: mp){
            cout<<it.second<<" ";
        }
    }

void bottomView(node *root)
    {
        if(root == NULL) return;
        map<int,int> mp;
        queue<pair<node*,int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            node* Node = it.first;
            int line = it.second;
            
            mp[line] = Node->data;
            
            if(Node->left) q.push({Node->left,line-1});
            if(Node->right) q.push({Node->right,line+1});
        }
        
        for(auto it: mp){
            cout<<it.second<<" ";
        }
    }



int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    leftView(root);
    cout<<endl;
    rightView(root);
    cout<<endl;
    topView(root);
    cout<<endl;
    bottomView(root);
    cout<<endl;
    return 0;
} 