#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, int val){
    
    node* n = new node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

    int length(node* head){
        node* temp = head;
        int l=0;
        
        while(temp!=NULL){
            l++;
            temp = temp->next;
        }
        return l;
    }
    
    // T.C - O(n) + O(n/2), S.C - O(1)
    node* middleNode(node* head) {
        int l = length(head);
        node* temp = head;
        int c=1;
        
        while(temp!=NULL && c!=(l/2)+1) 
        {
            temp = temp->next;
            c++;
        }
        return temp;
    }

    //T.C - O(n/2), S.C - O(1)
    node* middleNode2(node* head){
        node* fast;
        node* slow;
        fast = slow = head;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtTail(head,15);
    node* newhead = middleNode(head);
    display(newhead);
    cout<<endl;
    node* newhead2 = middleNode2(head);
    display(newhead2);
}