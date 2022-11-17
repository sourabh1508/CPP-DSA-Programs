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
    class solution{

        Node* prev;
        Node* first;
        Node* mid;
        Node* last;

        public:
        void inorder(Node* root){
            if(root == NULL) return;
            inorder(root->left);
            
            if(prev!=NULL && (root->data < prev->data)){
                if(first == NULL){
                    first = prev;
                    mid = root;
                }
                else{
                    last = root;
                }
            }
            prev = root;
            inorder(root->right);
        }

        void recoverTree(Node* root) {
            first = mid = last = NULL;
            prev = new Node(INT_MIN);
            inorder(root);
            if(first && last) swap(first->data, last->data);
            else if(first && mid) swap(first->data, mid->data);
        }
    };
    
    
    void preorder(Node* root){
        if(root == NULL) return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    solution obj;
    obj.recoverTree(root);
    preorder(root);
    return 0; 
}