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

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    node* temp = head;

    if(head==NULL){
        n->next = n;
        head = n;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = n; 
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;

    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAtHead(node* &head){
    node* temp = head;
    
    while(temp->next!=head){
        temp=temp->next;
    }
    node* todelete = head;
    temp->next = head->next;
    head=head->next;
    delete todelete;
}

void deletion(node* &head, int pos){
    
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    
    node* temp = head;
    int c=1;
    while(c!=pos-1){
        temp=temp->next;
        c++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<"NULL"<<endl;

}


int main()
{
    node* head=NULL;
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,7);
    insertAtTail(head,15);
    display(head);
    insertAtHead(head, 27);
    display(head);
    deletion(head, 4);
    display(head);
    deleteAtHead(head);
    display(head);
    return 0;
}