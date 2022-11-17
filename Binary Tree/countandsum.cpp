#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node* left;
  struct node* right;

  node(int val){
      data = val;
      left = NULL;
      right = NULL;
  }  
};

//O(n)
int count(node* root){
    if(root==NULL){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

int sum(node* root){
    if(root==NULL){
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->data;
}

//Optimal Approach for count nodes O(sq(Logn))
    int LeftHeight(node* root){
        int ans = 0;
        while(root){
            ans++;
            root = root->left;
        }
        return ans;
    }
    
    int RightHeight(node* root){
        int ans = 0;
        while(root){
            ans++;
            root = root->right;
        }
        return ans;
    }
    
    int countNodes(node* root) {
        if(root==NULL) return 0;
        
        int lh = LeftHeight(root);
        int rh = RightHeight(root);
        
        if(lh==rh) return (1<<lh) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }


int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<"Count of Nodes: "<<count(root)<<endl;
    cout<<"Count of Nodes optimised: "<<countNodes(root)<<endl;
    cout<<"Sum of Nodes: "<<sum(root)<<endl;
    return 0;
}