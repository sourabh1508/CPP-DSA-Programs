#include<bits/stdc++.h>
using namespace std;

class Stack{
    deque<int> q;

    public:
    void push(int x){
        q.push_back(x);
    }
    int pop(){
        if(q.empty())
        {
            cout<<"No element to pop"<<endl;
            return 0;
        }
        int e = q.back();
        q.pop_back();
        return e;
    }
    void display(){
        deque<int> tempq = q;
        while(!tempq.empty()){
            cout<<tempq.back()<<" ";
            tempq.pop_back();
        }
        cout<<endl;
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    st.pop();
    st.pop();
    st.display();
    st.push(40);
    st.display();
}