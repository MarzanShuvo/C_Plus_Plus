#include<iostream>
using namespace std;

// this will force to implement the Print function in child class
// this a interface and it has no data member

/* Every class that has a virtual function has a virtual table. 
Whenever you use a reference to this class and call a virtual function, 
it will be looked up in the virtual table at runtime. */

class Printable
{

public:
    virtual void Print() const =0;
};



//Base class is Rect
class Rect : public Printable
{
protected:
    int width_=0;
    int height_=0;
public:
    Rect(int w, int h) : width_{w}, height_{h} {}
    // it will show a error as Print function is not defined.
    void Print() const override{
        cout<<"Rect: "<< height_<<" "<<width_<<endl;
    }
    
};

//derived class is Square
//Square is a child of Rect
class Square :public Rect
{
public:
    //explicit should forbide int-> float conversion
    //The explicit function specifier controls unwanted implicit type conversions
    explicit Square(int size) : Rect(size, size){}
    //override is used to patent the Print function only for Squares
    void Print() const override{
        cout<<"Square: "<< height_<<" "<<width_<<endl;
    }
    
};
// this is a just a function
void Print(const Printable& rect) { rect.Print();}

int main(int argc, char const *argv[])
{
    Square square(10);
    Rect rect(20,10);
    Print(square);
    Print(rect);
    
    // with virtaul -> square
    // without virtual -> Rect
    // const Rect& rect_ref = square;
    // rect_ref.Print();
    return 0;
}
