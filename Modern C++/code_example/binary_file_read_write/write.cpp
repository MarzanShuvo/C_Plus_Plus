# include <fstream> // for the file streams
# include <vector>
using namespace std;
int main () {
    string file_name = "image .dat";
    ofstream file(file_name , ios_base::out | ios_base::binary );
    if (! file) { return EXIT_FAILURE ; }
    int r = 2; int c = 3;
    vector <float > vec(r * c, 42);
    file.write( reinterpret_cast <char *>(&r), sizeof (r));
    file.write( reinterpret_cast <char *>(&c), sizeof (c));
    file.write( reinterpret_cast <char *>(& vec.front ()),
    vec.size() * sizeof (vec.front()));
    return 0;
}