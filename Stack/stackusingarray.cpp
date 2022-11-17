#include<iostream>
using namespace std;

#define n 5

class stack{
    int* arr;
    int top;

    public:
    stack(){
        arr = new int[n];
        top = -1;
    }
    void push(int x){
        if(top==n-1)
            cout<<"Stack Overflow"<<endl;
        else
        {
            top++;
            arr[top]=x;
        }      
    }
    void pop(){
        if(top==-1){
            cout<<"No Element to Pop"<<endl;
        }
        else
        {
            top--;
        }
    }
    int Top(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    bool empty(){
        if(top==-1)
            return true;
        else
            return false;
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.Top()<<endl;
    s.pop();
    cout<<s.Top()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.empty()<<endl;

    return 0;
}