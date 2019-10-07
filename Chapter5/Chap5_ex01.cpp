#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { this->radius = 1; }
	Circle(int r) { this->radius = r; }
	~Circle() {}
	void setRadius(int r) { this->radius = r; }
	int getRadius() { return this->radius; }	
};

void swap(Circle& a, Circle& b) {
	Circle tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main() {
	Circle waffle(30);
	Circle pizza(50);
	swap(waffle, pizza);
	cout << waffle.getRadius();
}