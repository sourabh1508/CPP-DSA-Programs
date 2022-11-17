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

void inorder(Node* root, unordered_set<int> &s){
        if(root==NULL)
            return;
        inorder(root->left, s);
        s.insert(root->data);
        inorder(root->right, s);
    }

void countPairsUtil(Node* root, unordered_set<int> &s, int x, int &c)
    {
        if(root==NULL)
            return;
        
        
        if(s.find(x-root->data)!=s.end()){
            c++;
        }
        
        countPairsUtil(root->left, s, x, c);
        countPairsUtil(root->right, s, x, c);
    }

int countPairs(Node* root1, Node* root2, int x)
    {
        unordered_set<int> s;
        inorder(root1, s);
        int c=0;
        countPairsUtil(root2, s, x, c);
        return c;
    }

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    Node* root2 = new Node(4);
    root2->left = new Node(3);
    root2->right = new Node(5);
    cout<<countPairs(root1, root2, 6);
    return 0;
}