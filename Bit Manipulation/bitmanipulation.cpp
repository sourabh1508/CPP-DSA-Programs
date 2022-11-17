#include<iostream>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos))!=0);
}

int setBit(int n, int pos){
    return (n | (1<<pos));
}

int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}

int updateBit(int n, int pos, int val){
    n = n & (~(1<<pos));
    return (n | val<<pos);
}

int main(){
    cout<<"GetBit: "<<getBit(5,2)<<endl;
    cout<<"SetBit: "<<setBit(5,1)<<endl;
    cout<<"ClearBit: "<<clearBit(5,0)<<endl;
    cout<<"UpdateBit: "<<updateBit(5,0,0)<<endl;
}