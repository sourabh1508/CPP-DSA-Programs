#include<bits/stdc++.h>
using namespace std;


class Stack{
    queue<int> q;

    public:
    void push(int x){
        q.push(x);
        for(int i=1;i<=q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    int pop(){
        if(q.empty())
        {
            cout<<"No element to pop"<<endl;
            return 0;
        }
        int e = q.front();
        q.pop();
        return e;
    }
    void display(){
        queue<int> tempq = q;
        while(!tempq.empty()){
            cout<<tempq.front()<<" ";
            tempq.pop();
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