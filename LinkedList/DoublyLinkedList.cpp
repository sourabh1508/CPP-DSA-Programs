#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

void deleteAtHead(node* &head){
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node* &head, int pos){
    
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int c=1;

    while(temp!=NULL && c!=pos)
    {
        temp=temp->next;
        c++;
    }
    temp->prev->next = temp->next;
    
    if(temp->next!=NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    
    head=n;
}

void insertAtTail(node* &head, int val){  
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }

    node* n = new node(val);
    node* temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void display(node* head){
    node* temp = head;
    cout<<"NULL ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    insertAtTail(head, 9);
    insertAtHead(head, -2);
    display(head);
    deletion(head, 3);
    deleteAtHead(head);
    display(head);
}

