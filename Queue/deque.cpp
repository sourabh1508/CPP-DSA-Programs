#include<bits/stdc++.h>
using namespace std;
#define n 5

class DeQueue{
    int* arr;
    int qfront;
    int qrear;

    public:
    DeQueue(){
        arr = new int[n];
        qfront = -1;
        qrear = -1;
    }

    void push_front(int x){
        if((qfront==0 && qrear == n-1) || (qrear == (qfront-1)%(n-1))){
            cout<<"Queue is Full"<<endl;
            return;
        } 
        else if(qfront == -1){
            qfront = qrear = 0;
        } 
        else if(qfront == 0 && qrear != n-1){
            qfront = n-1;
        }
        else{
            qfront--;
        }
        arr[qfront] = x;
    }

    void push_back(int x){
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

    void pop_front(){
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

    void pop_back(){
        if(qfront == -1){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        arr[qrear] = -1;
        if(qfront == qrear){
            qfront = -1;
            qrear = -1;
        }
        else if(qrear == 0){
            qrear = n-1;
        }
        else{
            qrear--;
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
    DeQueue Q;
    Q.push_front(1);
    Q.push_back(3);
    Q.push_back(5);
    Q.push_back(9);
    Q.push_front(7);
    Q.display();
    Q.pop_back();
    Q.pop_front();
    Q.display();
}