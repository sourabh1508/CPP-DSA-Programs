#include<bits/stdc++.h>
using namespace std;
#define n 5

class CQueue{
    int* arr;
    int qfront;
    int qrear;

    public:
    CQueue(){
        arr = new int[n];
        qfront = -1;
        qrear = -1;
    }

    void Enqueue(int x){
        if((qfront==0 && qrear == n-1) || (qrear == (qfront-1)%(n-1))){
            cout<<"Queue is Full"<<endl;
            return;
        }
        else if(qfront == -1){
            qfront = qrear = 0;
        }
        else if(qrear == n-1 && qfront!=0){
            qrear = 0;
        }
        else{
            qrear++;
        }
        arr[qrear] = x;
    }

    void Dequeue(){
        if(qfront == -1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        arr[qfront] = -1;
        if(qfront == qrear){
            qfront = -1;
            qrear = -1;
        }
        else if(qfront== n - 1){
            qfront = 0;
        }
        else{
            qfront++;
        }
    }
    void display(){
        if(qfront<=qrear){
            for(int i=qfront;i<=qrear;i++){
            cout<<arr[i]<<" ";
            }
        }
        else{
            for(int i=0;i<=qfront;i++){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
        
    }
};

int main(){
    int arr[n];
    CQueue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.display();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.display();
    q.Enqueue(6);
    q.Enqueue(7);
    q.Enqueue(8);
    q.display();
}