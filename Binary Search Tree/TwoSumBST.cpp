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

class BSTIterator {
    stack<Node*> st;
    bool reverse = true; //true for before and false for next
    
public:
    BSTIterator(Node* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        Node* node = st.top();
        st.pop();
        if(reverse == true) pushAll(node->left); //before
        else pushAll(node->right); //next
        return node->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(Node* root){
        while(root!=NULL){
            st.push(root);
            if(reverse==true) root = root->right; //before
            else root = root->left;  //next
        }
    }
};

bool findSum(Node* root, int k){
    if(root==NULL) return false;
    BSTIterator low(root, false); //next
    BSTIterator high(root, true); //before

    int i = low.next();
    int j = high.next();

    while(i<j){
        if(i+j==k) return true;
        else if(i+j < k) i = low.next();
        else j = high.next();
    }
    return false;
}

int main(){
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    int k = 3;
    cout<<findSum(root, k);
    return 0; 
}