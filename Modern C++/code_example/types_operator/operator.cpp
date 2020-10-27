#include <iostream>
using std :: cout; using std :: endl;

class Hmm {
public :
    //default constructor
    Hmm () { cout << " default " << endl; }
    //copy constructor
    Hmm( const Hmm& other) { cout << "copy" << endl; }
    //move constructor
    Hmm(Hmm && other) { cout << "move" << endl; }
    //copy operator
    Hmm& operator =( const Hmm& other) {
        cout << "copy operator " << endl; return *this;
    }
    //move operator
    Hmm& operator =( Hmm && other) {
        cout << "move operator " << endl; return *this;
    }
};


int main () {
Hmm a;
Hmm b = a;
a = b;
Hmm c = std :: move(a);
c = std :: move(b);
return 0;
}