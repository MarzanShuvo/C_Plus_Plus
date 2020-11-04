template <class T>
class MyClass {
    public :
    MyClass ( const T& smth) : smth_(smth) {}
    private :
    T smth_;
};
int main(int argc , char const * argv []) {
    MyClass <int> my_object(10);
    MyClass <double> my_double_object(10.0);
return 0;
}