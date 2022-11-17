#include<bits/stdc++.h>
using namespace std;

class KQueue{
    public:
    int n;
    int k;
    int *arr;
    int *next;
    int *front;
    int *rear;
    int free;

    
    KQueue(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        for(int i=0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        for(int i=0;i<n;i++) next[i] = i+1;
        next[n-1] = -1;
        free = 0;
    }
    void enqueue(int x, int qn){
        if(free == -1) return;
        int index = free;
        free = next[index];

        if(front[qn-1] == -1) front[qn-1] = index;
        else{
            next[rear[qn-1]] = index;
        }
        next[index] = -1;
        rear[qn-1] = index;
        arr[index] = x;
    }
    int dequeue(int qn){
        if(front[qn-1] == -1) return -1;
        int index = front[qn-1];
        front[qn-1] = next[index];
        next[index] = free;
        free = index;

        return arr[index];
    }
};

int main(){
    KQueue q(10, 3);
    q.enqueue(4, 1);
    q.enqueue(5, 1);
    q.enqueue(7, 2);
    cout<<q.dequeue(2);
}