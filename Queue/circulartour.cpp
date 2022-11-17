#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

int main(){

    int n;
    cin>>n;
    petrolPump p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].petrol>>p[i].distance;
    }
    int deficit = 0;
    int balance = 0;
    int start = 0;
       
    for(int i=0;i<n;i++){
        balance += p[i].petrol - p[i].distance;
        if(balance < 0){
            deficit += balance;
            balance = 0;
            start = i+1;
        }
    }
    if(balance + deficit >= 0){
        cout<<start;
    }
    else{
        cout<<"-1";
    }
}
