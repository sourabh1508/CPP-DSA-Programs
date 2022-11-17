#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int temp = n;
    int sum=0;
    while(temp>0)
    {
        int x=temp%10;
        sum = sum + (x*x*x);
        temp /= 10;
    }

   if(n==sum)
   {
       cout<<"Armstrong Number"<<endl;           
   }
   else
   {
       cout<<"Not an armstrong number"<<endl;
   }

 
}