#include<iostream>
#include<string>
using namespace std; // Save space on slides .

class Printer
{
private:
    std::string some_str;
public:
    void Print( const string & str) {
        cout << " lvalue : " << str << endl;
    }

    void Print( string && str) {
        some_str = str;
        cout << " rvalue : " << some_str << endl;
    }
    
};




int main () {
string hello = "hi";
Printer printer;
printer.Print (hello);
printer.Print (" world "); // this will call the rvalue functions
printer.Print (std :: move(hello)); // std::move used to move rvalue to different lvalues
// DO NOT access " hello " after move!
//cout<< "after move :"<< hello<< endl; // for understanding the error after move
// not use the lvalue after std::move, it can be empty
return 0;
}