#include<iostream>
#include<cmath>
#include<algorithm>

int main()
{
    size_t size = 100 * 1000 * sizeof(char);
    int array[size];
    while(true){
        size = size+100 * 1000 * sizeof(char);
        array[size];
        std::cerr << size << std::endl;
    }

    return 0;
}
