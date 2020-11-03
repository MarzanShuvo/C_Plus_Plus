# include <iostream>
# include <string>
using namespace std;
enum class Channel { STDOUT , STDERR };

void Print( Channel print_style , const string & msg) {
    switch ( print_style ) {
    case Channel :: STDOUT :
    cout << msg << endl;
    break ;
    case Channel :: STDERR :
    cerr << msg << endl;
    break ;
    default :
    cerr << " Skipping \n";
}
}
int main () {
Print ( Channel :: STDOUT , " hello ");
Print ( Channel :: STDERR , " world ");
return 0;
}