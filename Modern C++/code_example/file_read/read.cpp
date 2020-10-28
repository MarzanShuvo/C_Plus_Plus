# include <fstream> // For the file streams .
# include <iostream>
# include <string>
using namespace std; // Saving space .
int main () {
int i;
double a, b;
string s;
// Create an input file stream .
ifstream in("test_cols.txt", ios_base ::in);
// Read data , until it is there .
while (in >> i >> a >> s >> b) {
cerr << i << ", " << a << ", "
<< s << ", " << b << endl;
}
return (0);
}