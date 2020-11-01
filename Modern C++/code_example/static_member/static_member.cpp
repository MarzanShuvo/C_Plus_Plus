# include <math.h>
# include <iostream>
using std::cout; using std::endl;
class Point {
    public :
        Point(int x, int y) : x_(x), y_(y) {}
        // for this class function
        float Distance(const Point& other) const{
            int diff_x = x_ - other.x_;
            int diff_y = y_ - other.y_;
            return sqrt( diff_x * diff_x + diff_y * diff_y );
        }
        //static function
        static float dist(const Point& a, const Point& b) {
            int diff_x = a.x_ - b.x_;
            int diff_y = a.y_ - b.y_;
            return sqrt( diff_x * diff_x + diff_y * diff_y );
        }
    private :
        int x_ = 0; int y_ = 0;
};
int main () {
Point a(2, 2), b(1, 1);
cout << "Dist is (static function) " << Point :: dist(a, b) << endl;
cout << "Dist is (object function)" << a.Distance(b) << endl;
return 0;
}