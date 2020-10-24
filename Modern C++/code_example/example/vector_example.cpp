#include<iostream>
#include<vector>

int main(int argc, char const *argv[])
{
    std::vector<int> vec={1,2};
    vec.push_back(3);
    std::cout << vec.front()<<" "<<vec.back()<< std::endl;

    return 0;
}
