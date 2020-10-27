# include <iostream>
using std :: cout; using std :: endl;

//base class
class Rectangle {
public :
    Rectangle (int w, int h) : width_ {w}, height_ {h} {}
    int width () const { return width_ ; }
    int height () const { return height_ ; }
protected :
    int width_ = 0;
    int height_ = 0;
};

//inherited class
class Square : public Rectangle {
public :
explicit Square (int size) : Rectangle {size , size} {}
};

//main function
int main () {
Square sq (10); // Short name to save space .
cout << sq.width() << " " << sq.height() << endl;
return 0;
}