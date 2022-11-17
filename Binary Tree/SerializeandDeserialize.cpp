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

    string serialize(Node* root) {
        if(root==NULL) return "";
        string s;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node==NULL){
                s += "#,";
            }
            else{
                s.append(to_string(node->data) + ',');
            }
            if(node!=NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        Node* root = new Node(stoi(str));
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            getline(s, str, ',');
            
            if(str=="#"){
                node->left = NULL;
            }
            else{
                Node* leftNode = new Node(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(s, str, ',');
            
            if(str=="#"){
                node->right = NULL;
            }
            else{
                Node* rightNode = new Node(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    string s = serialize(root);
    cout<<s<<endl;
    Node* node = deserialize(s);
    preorder(root);
}