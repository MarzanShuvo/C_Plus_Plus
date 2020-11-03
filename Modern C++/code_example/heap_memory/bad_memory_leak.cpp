# include <iostream>
# include <cmath>
# include <algorithm>
using std::cout; using std::endl;
int main () {
    double *data = nullptr ;
    size_t size = pow (1024 , 3) / 8; // Produce 1GB
    for (int i = 0; i < 5; ++i) {
        // Allocate memory for the data.
        data = new double [size ];
        std :: fill(data , data + size , 1.23);
        // Do some important work with the data here.
        cout << " Iteration : " << i << " done!" << endl;
    }
    // This will only free the last allocation !
    delete [] data;
    int unused ; std::cin >> unused ; // Wait for user.
    return 0;
}