#include<iostream>
using namespace std;
#define n 100


class twoStacks{
    int* arr;
    int top1;
    int top2;

    public:
    twoStacks(){
        arr = new int[n];
        top1 = n/2 + 1;
        top2 = n/2;
    }

    void push1(int x){
        if(top1<0){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top1--;
        arr[top1]=x;
    }

    void push2(int x){
        if(top2>=n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top2++;
        arr[top2]=x;
    }

    int pop1(){
        if(top1>n/2){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top1++];
    }

    int pop2(){
        if(top2<n/2 + 1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top2--];
    }

};

int main(){
    twoStacks ts;
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
}