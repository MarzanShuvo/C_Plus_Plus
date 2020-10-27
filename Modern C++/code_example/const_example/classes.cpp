#include <iostream>
using std::cout;
using std::endl;

class Blah{
    public:
        void SomeFunc() {cout<< "none const" << endl;}
        void SomeFunc() const {cout<< "const" << endl;}
};

int main()
{
    Blah blah;
    blah.SomeFunc();

    const Blah& blah_ref = blah;
    blah_ref.SomeFunc();
    return 0;
}
