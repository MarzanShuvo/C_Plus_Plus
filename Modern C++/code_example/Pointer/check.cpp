#include<iostream>
using std::cout;
using std::endl;

struct A
{
    int data =20;
};


int main()
{
    A a;
    A& a_ref = a;
    cout<<a_ref.data<<endl;
    A b ;
    b.data = 300;
    a_ref = b;
    cout<<a_ref.data<<endl;
    cout<<a.data<<endl;
    
    return 0;
}
