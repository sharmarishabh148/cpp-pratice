#include <iostream>
using namespace std;
class Sum {
  public:
    int addition(int a, int b) {
      return a + b;
    }

    int addition(int a, int b, int c) {
      return a + b + c;
    }
};

class Area {
  public:
    double calculateArea(double length, double breadth) {
      return length * breadth;
    }

    double calculateArea(double side) {
      return side * side;
    }
};


int main(void) {
  Sum sum;
  cout << sum.addition(14, 35) << endl;
  cout << sum.addition(31, 34, 43) << endl;

  Area area;
  cout << "Area of rectangle = " << area.calculateArea(3, 4) << endl;
  cout << "Area of square = " << area.calculateArea(6) << endl;
  return 0;
}
