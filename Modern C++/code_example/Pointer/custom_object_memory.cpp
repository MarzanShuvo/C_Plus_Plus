# include <iostream>
using std::cout; using std::endl;



class MemoryTester {
 public :

    int i;
    double d;
    void SetData ( float data) { data_ = data; }
    float * GetDataAddress() { return &data_; }
 private :

    float data_; // position of types is important
};

int main () {
    MemoryTester tester ;
    tester.i = 1; tester.d = 2; tester.SetData(3);
    cout << " Sizeof tester : " << sizeof(tester) << endl;
    cout << " Address of i: " << &tester.i << endl;
    cout << " Address of d: " << &tester.d << endl;
    cout << " Address of _data : "
    << tester.GetDataAddress()<< endl;
    return 0;
}

// memory :
//|i|i|i|i|_|_|_|_|d|d|d|d|d|d|d|d|...
// who is who: | int i | padding |
//double d
//|...