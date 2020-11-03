# include <iostream>
# include <memory>

struct A {
    int a = 10;
};

//unique pointer can not be copied but can be moved.
int main() {
    auto a_ptr = std::unique_ptr <A>( new A);
    std::cout << a_ptr->a << std::endl;
    auto b_ptr = std::move(a_ptr);
    std::cout << b_ptr->a << std::endl;
    //ownership changed
    std::cout << a_ptr->a << std::endl;
    return 0;
}