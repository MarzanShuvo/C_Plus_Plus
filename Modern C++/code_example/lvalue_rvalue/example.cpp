#include<iostream>
#include<string>
using namespace std; // Save space on slides .
void Print( const string & str) {
cout << " lvalue : " << str << endl;
}

void Print( string && str) {
cout << " rvalue : " << str << endl;
}


int main () {
string hello = "hi";
Print (hello);
Print (" world "); // this will call the rvalue functions
Print (std :: move(hello)); // for making rvalue from lvalue
// DO NOT access " hello " after move!
return 0;
}