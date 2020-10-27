#include <algorithm>
#include <vector>
using namespace std;

class Human {
public :
Human (int kindness ) : kindness_ { kindness } {}
bool operator <( const Human& other) const {
return kindness_ < other. kindness_ ;
}
private :
int kindness_ = 100;
};


int main () {
vector <Human > humans = {Human{0}, Human{10}};
std :: sort( humans.begin (), humans.end ());
return 0;
}