#include <iostream>
using namespace std;

class Circle {
  //define data attributes
  double radius;
  double pi;

  public:
  //define constructors
  Circle() {
    radius = 0;
    pi = 3.142;
  }
  Circle(double r) {
    radius = r;
    pi = 3.142;
  }

  //define methods
  double area() {
    return pi * radius * radius;
  }

  double perimeter() {
    return 2 * pi * radius;
  }
};

int main() {
  Circle circle(5);
  cout << "Area: " << circle.area() << endl;
  cout << "Perimeter: " << circle.perimeter() << endl;
}
