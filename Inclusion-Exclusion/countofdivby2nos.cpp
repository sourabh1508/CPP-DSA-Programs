#include<iostream>
using namespace std;

void divby2nos(int n,int a,int b)
{
    int c1=n/a;
    int c2=n/b;
    int c3=n/(a*b);

    cout<<(c1+c2-c3);

}

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    divby2nos(n,a,b);
}