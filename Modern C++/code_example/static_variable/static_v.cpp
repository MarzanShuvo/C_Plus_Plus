# include <iostream>
using std :: cout; using std :: endl;
struct Counted {
    Counted(){ Counted::count++; }
    ~ Counted(){ Counted::count--; }
    static int count; // Static counter member .
};

int Counted::count = 0; // Definition .
int main () {
Counted a, b;
cout << "Count : " << Counted::count << endl;
Counted c;
cout << "Count : " << Counted::count << endl;
return 0;
}