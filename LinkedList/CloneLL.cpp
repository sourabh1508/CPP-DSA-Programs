#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

//First Approach -> T.C - O(2N), S.C - O(N) 
Node* copyList(Node *head)
    {
        Node* temp = head;
        Node* copy;
        unordered_map<Node*, Node*> mp;
        
        copy = new Node(temp->data);
        mp[temp] = copy;
        
        while(temp->next != NULL){
            copy->next = new Node(temp->next->data);
            temp = temp->next;
            copy = copy->next;
            mp[temp] = copy;
        }
        temp = head;
        
        while(temp != NULL){
            mp[temp]->arb = mp[temp->arb];
            temp = temp->next;
        }
        return mp[head];
    }

//Second Approach -> T.C - O(3N), S.C - O(1)
Node* copyRandomList(Node* head) {
        Node* iter = head;
        
        Node* nxt = head;
        while(iter != NULL){
            nxt = iter->next;
            
            Node* copy = new Node(iter->data);
            iter->next = copy;
            copy->next = nxt;

            iter = nxt;
        }
        
        iter = head;
        
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        Node dummy(INT_MIN);
        Node* copy = &dummy;
        
        iter = head;
        
        while(iter != NULL){
            nxt = iter->next->next;
            copy->next = iter->next;
            iter->next = nxt;
            
            copy = copy->next;
            iter = nxt;
        }
        
        return dummy.next;    
    }
