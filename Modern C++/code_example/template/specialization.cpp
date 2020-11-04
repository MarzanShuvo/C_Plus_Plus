// Function definition .
template <typename T>
T DummyFuncion () {
    T result ;
    return result ;
}
template <>
int DummyFuncion () {
    return 42;
}
int main () {
    DummyFuncion <int >();
    DummyFuncion <double >();
    return 0;
}