# include <iomanip> // For setprecision .
# include <fstream>
using namespace std;
int main () {

    string filename = "out.txt";
    ofstream outfile(filename);
    if (! outfile.is_open()) { return EXIT_FAILURE ; }
    double a = 1.123123123;
    outfile << "Just string " << endl;
    outfile << setprecision(20) << a << endl;
    return 0;
}