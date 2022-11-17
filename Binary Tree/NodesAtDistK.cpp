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

    void markParent(Node* root, Node* target, unordered_map<Node*, Node*> &parent){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front(); q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
    vector<int> distanceK(Node* root, Node* target, int k) {
        unordered_map<Node*, Node*> parent;
        markParent(root, target, parent);
        
        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        q.push(target);
        vis[target] = true;
        int cur_lvl = 0;
        
        while(!q.empty()){
            int size = q.size();
            if(cur_lvl == k) break;
            cur_lvl++;
            for(int i=0;i<size;i++){
                Node* curr = q.front(); q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            ans.push_back(temp->data);
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

    vector<int> v = distanceK(root, root->left->right, 2);
    for(int i=0;i<v.size();i++) 
        cout<<v[i]<<" ";
}