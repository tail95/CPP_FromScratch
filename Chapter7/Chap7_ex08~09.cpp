#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius= " << radius << "인 원" << endl; }
	friend Circle& operator ++(Circle& a);
	friend Circle operator ++(Circle& a, int x);
	friend Circle operator +(int r, Circle c);
};

Circle& operator ++(Circle& a) {  // 전위 연산자
	a.radius++;
	return a;
}
Circle operator ++(Circle& a, int x) { // 후위 연산자
	Circle tmp = a;
	a.radius++;
	return tmp;
}
Circle operator +(int r, Circle c) {
	Circle tmp;
	tmp.radius = r + c.radius;
	return tmp;
}

int main() {
	//8
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
	cout << endl;

	//9
	Circle c(5), d(4);
	d = 1 + c;
	c.show();
	d.show();
}