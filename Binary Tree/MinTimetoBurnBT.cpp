#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;

  Node(int val){
      data = val;
      left = NULL;
      right = NULL;
  }  
};

Node* markParent(Node* root, unordered_map<Node*, Node*> &parent, int target){
        queue<Node*> q;
        q.push(root);
        Node* node;
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            if(curr->data == target) node = curr;
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return node;
    }
    
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parent;
        Node* targ = markParent(root, parent, target); 
        int ans = 0;
        unordered_map<Node*,bool> vis;
        vis[targ] = 1;
        queue<Node*> q;
        q.push(targ);
        while(!q.empty()){
            bool fl = 0;
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* curr = q.front(); q.pop();
                if(parent[curr] && !vis[parent[curr]]){
                    fl = 1;
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
                if(curr->left && !vis[curr->left]){
                    fl = 1;
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    fl = 1;
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
            }
            if(fl) ans++;
        }
        return ans;
    }

    int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<minTime(root, 7);
}