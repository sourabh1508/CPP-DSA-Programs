#include<iostream>
using namespace std;

class Cube {
private:
    int n;
public:
    Cube(int num = 1) 
    {
	n = num;
    }
     
    Cube operator ^ (Cube &obj) {
        Cube res;
        res.n = n * n * obj.n;
        return res;
    }
    void print() { cout << n*n*n; }
};
 
int main()
{
    int n, cub;
    cin>>n;
    for (int i = 1; i <= n; i++) 
    {
        Cube c1(i);
    	c1.print();
        cout<<endl;
    }
    
}