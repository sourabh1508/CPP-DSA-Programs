#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

struct compare{
        bool operator()(struct Node* a, struct Node* b){
        return a->data > b->data; 
        }  
    };
    
    
    
    Node * mergeKLists(Node *arr[], int K)
    {
           priority_queue<Node*, vector<Node*>, compare> pq;
           for(int i=0;i<K;i++){
               pq.push(arr[i]);
           }
           
           Node* dummy = new Node(0);
           Node* last = dummy;
           
           while(!pq.empty()){
               Node* current = pq.top();
               pq.pop();
               last->next = current;
               last = current;
               if(current->next!=NULL)
                    pq.push(current->next);
           }
           return dummy->next;
    }


void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

int main(){
    int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
        }
        Node *res =mergeKLists(arr,N);
		printList(res);

    
}