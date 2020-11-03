# include <iostream>
# include <memory>
class A {
    public:
        A(int a) { std::cout << "I'm alive !\n"; }
        ~A() { std::cout << "I'm dead ... :(\n"; }
};
int main () {
    // Equivalent to: std :: shared_ptr <A>( new A(10));
    auto a_ptr = std::make_shared <A>(10);
    std::cout << a_ptr.use_count() << std::endl;
    {
        auto b_ptr = a_ptr;
        std::cout << a_ptr.use_count() << std::endl;
    }
    std :: cout << "Back to main scope \n";
    std :: cout << a_ptr.use_count() << std :: endl;
    return 0;
}