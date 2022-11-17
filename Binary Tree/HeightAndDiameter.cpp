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

int calcHeight(node* root){
    if(root==NULL){
        return 0;
    }
    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);
    return max(lh, rh)+1;
}

//BruteForce Approach
int calcDiameter(node* root){
    if(root==NULL){
        return 0;
    }
    int lh = calcHeight(root->left);
    int rh = calcHeight(root->right);
    int currDiameter = lh+rh+1;
    int leftDiameter = calcDiameter(root->left);
    int rightDiameter = calcDiameter(root->right);
    return max(currDiameter, max(leftDiameter,rightDiameter));
}

//Optimised Approach
int calcDiameterOp(node* root, int* height){
    if(root==NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = calcDiameterOp(root->left, &lh);
    int rd = calcDiameterOp(root->right, &rh);
    int currDiameter = lh + rh + 1;
    *height = max(lh, rh)+1;
    return max(currDiameter, max(ld, rd));
}

//Optimized Approach2
int diameter(node* root, int &ans){
    if(root==NULL) return 0;
    int lh = diameter(root->left, ans);
    int rh = diameter(root->right, ans);
    ans = max(ans, lh+rh+1);
    return max(lh,rh) + 1;
} 

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    cout<<calcHeight(root)<<endl;
    cout<<calcDiameter(root)<<endl;
    int h=0;
    cout<<calcDiameterOp(root,&h)<<endl;
    int dia = 0;
    diameter(root, dia);
    cout<<dia<<endl;
    return 0;
}