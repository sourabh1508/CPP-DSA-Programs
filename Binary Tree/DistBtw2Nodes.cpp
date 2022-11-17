#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* lca(Node* root, int n1, int n2){
        if(root==NULL)
            return NULL;
        
        if(root->data==n1 || root->data==n2)
            return root;
        
        Node* leftLCA = lca(root->left, n1, n2);
        Node* rightLCA = lca(root->right, n1, n2);
        
        if(leftLCA!=NULL && rightLCA!=NULL)
            return root;
        if(leftLCA!=NULL)
            return leftLCA;
        return rightLCA;
    }
    
    int dist(Node* root, int k, int d)
    {
        if(root==NULL)
            return -1;
            
        if(root->data==k)
            return d;
            
        int left = dist(root->left, k, d+1);
        int right = dist(root->right, k, d+1);

        if(left != -1) return left;
        return right;
    }
    
    int findDist(Node* root, int a, int b) {
        Node* Lca = lca(root, a, b);
        int d1 = dist(Lca, a, 0);
        int d2 = dist(Lca, b, 0);
        
        return d1+d2;
    }

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout<<findDist(root, 3, 4);
}