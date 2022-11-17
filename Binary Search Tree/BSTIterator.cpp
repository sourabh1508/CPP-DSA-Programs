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
    
public:
    BSTIterator(Node* root) {
        pushAll(root);
    }
    
    int next() {
        Node* node = st.top();
        st.pop();
        pushAll(node->right);
        return node->data;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(Node* root){
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }
    }
};

int main(){
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    
    BSTIterator* obj = new BSTIterator(root);
    int a = obj->next();
    bool b = obj->hasNext();

    cout<<a<<endl;
    cout<<b<<endl;
    return 0; 
}