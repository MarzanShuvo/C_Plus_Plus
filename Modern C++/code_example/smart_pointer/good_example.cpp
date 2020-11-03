// This is a good example of using smart pointers .
# include <iostream>
# include <vector>
# include <memory>
using std::cout; using std::unique_ptr ;

struct AbstractShape { // Structs to save space .
    virtual void Print() const = 0;
};
struct Square : public AbstractShape {
    void Print() const override { cout << " Square \n"; }
};
struct Triangle : public AbstractShape {
    void Print() const override { cout << " Triangle \n"; }
};
int main () {
    std::vector <unique_ptr < AbstractShape >> shapes ;
    shapes.emplace_back(new Square );
    auto triangle = unique_ptr <Triangle >(new Triangle);
    shapes.emplace_back(std::move( triangle ));
    for ( const auto& shape : shapes ) { shape ->Print (); }
    return 0;
}