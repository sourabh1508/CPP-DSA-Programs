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

node* mergeTwoLists(node* list1, node* list2) {
        node dummy(INT_MIN);
        node* dd = &dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->data <= list2->data){
                dd->next = list1;
                list1 = list1->next;
            }
            else{
                dd->next = list2;
                list2 = list2->next;
            }
            dd = dd->next;
        }
        dd->next = list1 ? list1: list2; 
        return dummy.next;
    }

node* merge2(node* head1, node* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    if(head1->data < head2->data){
        head1->next = merge2(head1->next, head2);
    }
    else{
        head2->next = merge2(head2->next, head1);
    }
    return head1->data < head2->data ? head1 : head2;
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,4);
    insertAtTail(head2,1);
    insertAtTail(head2,3);
    insertAtTail(head2,4);

    display(head1);
    cout<<endl;
    display(head2);
    cout<<endl;
    // node* newHead = mergeTwoLists(head1, head2);
    // display(newHead);
    // cout<<endl;
    node* newHead2 = merge2(head1, head2);
    display(newHead2);
    cout<<endl;
}