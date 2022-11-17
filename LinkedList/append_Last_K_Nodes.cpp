#include<iostream>
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

int length(node* head){
    int l=0;
    node* temp = head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* kAppend(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail = head;
    int c=1;
    int l=length(head);
    k=k%l;
    while(tail->next!=NULL){
        if(c==l-k)
        {
            newTail = tail;
        }    
        if(c==l-k+1)
        {
            newHead = tail;
        }
        tail=tail->next;
        c++;
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main()
{
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    node* newHead = kAppend(head, 3);
    display(newHead);
}