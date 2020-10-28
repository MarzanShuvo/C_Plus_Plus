#include<iostream>
using namespace std;

//Base class is Rect
class Rect
{
protected:
    int width_=0;
    int height_=0;
public:
    Rect(int w, int h) : width_{w}, height_{h} {}
    // virtual says that i have this function but my children can override this function
    virtual void Print() const{
        cout<<"Rect: "<< height_<<" "<<width_<<endl;
    }
    // int width() const {return width_;}
    // int height() const {return height_;}
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

void Print(const Rect& rect) { rect.Print();}

int main(int argc, char const *argv[])
{
    Square square(10);
    Rect rect(10, 20);
    Print(square);
    Print(rect);
    // with virtaul -> square
    // without virtual -> Rect
    // const Rect& rect_ref = square;
    // rect_ref.Print();
    return 0;
}
