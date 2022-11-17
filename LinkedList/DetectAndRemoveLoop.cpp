 #include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(Node* &head, int val){
    
    Node* n = new Node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
 
    void removeLoop(Node* head){
        Node* fast = head;
        Node* slow = head;
        Node* prev = head;

        while(fast!=NULL && slow!=NULL){
            prev = slow;
            fast = fast->next;
            if(fast!=NULL) fast = fast->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        if(fast != slow) return;
        
        fast = head;
        while(fast != slow){
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        prev->next = NULL;
    }

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    removeLoop(head);
    display(head);
    
}