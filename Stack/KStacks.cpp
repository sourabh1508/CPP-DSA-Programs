#include<iostream>
using namespace std;
#define n 100

class kStacks{
    int* arr;
    int* top;
    int* next;
    int free;

    public:
    kStacks(int k){
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        for(int i=0;i<k;i++){
            top[i] = -1;
        }
        for(int i=0;i<n-1;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;

        free = 0;
    }

    void push(int x, int sn){
        if(free == -1){
            cout<<"Stack is Full"<<endl;
            return;
        }
        int i = free;
        free = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = x;
    }

    int pop(int sn){
        if(top[sn] == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int i = top[sn];
        top[sn] = next[i];
        next[i] = free;
        free = i;

        return arr[i];
    }
};

int main(){
    kStacks ks(5);
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
 
    
}