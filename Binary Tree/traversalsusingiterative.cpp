#include<bits/stdc++.h>
#include<stack>
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

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    stack<node*> st;
    st.push(root);

    while(!st.empty()){
        struct node* curr = st.top();
        cout<<curr->data<<" ";
        st.pop();
        if(curr->right!=NULL){
            st.push(curr->right);
        }
        if(curr->left!=NULL){
            st.push(curr->left);
        }
    }
}

void inorder(struct node* root){
    stack<node*> s;
    node* curr = root;

    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";

        curr=curr->right;
    }
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    stack<node*> s1;
    stack<node*> s2;
    s1.push(root);
    struct node* curr;
    while(!s1.empty()){
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        

    if(curr->left!=NULL){
        s1.push(curr->left);
    }
    if(curr->right!=NULL){
        s1.push(curr->right);
    }
}
    while(!s2.empty()){
        curr = s2.top();
        cout<<curr->data<<" ";
        s2.pop();
    }
}

void postorder2(struct node* root){
    if(root==NULL) return;

    stack<node*> st;
    node* curr = root;

    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            node* temp = st.top()->right;
            if(temp!=NULL) curr = temp;
            else{
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
        }
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
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    postorder2(root);
    cout<<endl;
    return 0;
}