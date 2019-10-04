#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius) {
		this->radius = radius;
	}
	double getArea() {
		return 3.141592 * pow(this->radius, 2);
	}
};

int main() {
	Circle* circles = new Circle[3];
	int radius;
	int count = 0;
	for (int i = 0; i < 3; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> radius;
		circles[i].setRadius(radius);
		if (circles[i].getArea() > 100) count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl;
	delete circles;
}