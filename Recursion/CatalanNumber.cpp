#include<iostream>
using namespace std;

int Catalan(int n){
    if(n <= 1)
        return 1;
    int res=0;
    for(int i=0;i<=n-1;i++)
    {
        res += Catalan(i)*Catalan(n-i-1);
    }
    return res;
}

int main(){
    for(int i=0;i<=10;i++)
        cout<<Catalan(i)<<" ";
    return 0;
}