#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    float pi = M_PI;
    float l = 10000000;
    cout<<"pi: "<<pi<<endl;
    cout<< setprecision(20);
    cout<<"l: "<<l<<endl;
    cout<<"sum: "<<l+pi<<endl;
    return 0;
}
