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


class Large{
    public:
    int size;
    int max;
    int min;

    Large(int size, int max, int min){
        this->size = size;
        this->max = max;
        this->min = min;
    }
};

    Large largestBST(Node* root){
        if(root==NULL) // if root is null
            return Large(0, INT_MIN, INT_MAX);  
        
        //Post order Traversal
        Large left = largestBST(root->left);
        Large right = largestBST(root->right);
        
        //Check BST 
        if(left.max < root->data && right.min > root->data)
        {
            return Large(left.size + right.size + 1, max(root->data, right.max), min(root->data, left.min));
        }  
        return Large(max(left.size, right.size), INT_MAX, INT_MIN);
    }

int main(){
    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);
    cout<<largestBST(root).size<<endl;
    return 0; 
}