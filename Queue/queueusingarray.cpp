#include<bits/stdc++.h>
using namespace std;
#define n 100

class Queue{
    int* arr;
    int qfront;
    int qrear;

    public:
    Queue(){
        arr = new int[n];
        qfront = 0;
        qrear = 0;
    }

    void Enqueue(int x){
        if(qrear == n){
            cout<<"Queue is Full"<<endl;
            return;
        }
        arr[qrear++] = x;
    }

    void Dequeue(){
        if(qfront == qrear){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        arr[qfront++] = -1;
        if(qfront == qrear){
            qfront = 0;
            qrear = 0;
        }
    }
    void display(){
        for(int i=qfront;i<qrear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int arr[n];
    Queue q;
    q.Enqueue(1);
    q.Enqueue(3);
    q.Enqueue(5);
    q.display();
    q.Dequeue();
    q.display();
    
}