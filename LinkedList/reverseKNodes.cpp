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

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverseKNodes(node* head, int k){
    node* prevPtr = NULL;
    node* currPtr = head;
    node* nextPtr;
    int c=0;
    while(currPtr!=NULL && c<k){
        nextPtr = currPtr->next;
        currPtr->next = prevPtr; 
        prevPtr = currPtr;
        currPtr = nextPtr;
        c++;
    }
    if(nextPtr!=NULL){
        head->next = reverseKNodes(nextPtr, k);
    }
    return prevPtr;

}


int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,7);
    display(head);
    int k=3;
    node* newHead = reverseKNodes(head, k);
    display(newHead);
    return 0;
}