#include<iostream>
using namespace std;

class ComplexNumber {
private:
	int real, imaginary;
public:
	// Constructor
	ComplexNumber(int r = 0, int i = 0) {real = r; imaginary = i;}

	// Overloading function for + operator
	ComplexNumber operator + (ComplexNumber const &c) {
		ComplexNumber result;
		result.real = real + c.real;
		result.imaginary = imaginary + c.imaginary;
		return result;
	}

	// display results
	void display() {
		cout << "( " << real << " + " << imaginary << " i )" << '\n';
	}
};

int main() {
	ComplexNumber c1(11, 5), c2(2, 6);
	ComplexNumber c3 = c1 + c2;
	c3.display();
}
