    #include<bits/stdc++.h>
    using namespace std;
    
    struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

    vector<vector<int>> verticalTraversal(node* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<node*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            node* node = p.first;
            int vert = p.second.first;
            int level = p.second.second;
            nodes[vert][level].insert(node->data);
            if(node->left != NULL) q.push({node->left, {vert-1, level+1}});
            if(node->right != NULL) q.push({node->right, {vert+1, level+1}});
        }
        vector<vector<int>> ans;
        for(auto it: nodes){
            vector<int> temp;
            for(auto i: it.second){
                for(auto x: i.second)  temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }


int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    vector<vector<int>> ans = verticalTraversal(root);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
    }
    return 0;
}

