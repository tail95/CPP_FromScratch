#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return this->radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle :public Circle {
	string name;
public:
	NamedCircle() { this->setRadius(1); this->name = ""; }
	NamedCircle(int radius, string name) { this->setRadius(radius); this->name = name; }
	void setName(string name) { this->name = name; }
	string getName() { return this->name; }
	void show() { cout << "반지름이 " << this->getRadius() << "인 " << this->name; }
};

string largest(NamedCircle* p,int size = 5) {
	int result = 0;
	string name;
	for (int i = 0; i < size; i++) {
		if (result < p[i].getArea()) {
			result = p[i].getArea();
			name = p[i].getName();
		}
	}
	return name;
}
int main() {
	//1
	NamedCircle waffle(3, "waffle");
	waffle.show();
	cout << endl;

	//2
	int radius[5];
	string name[5];
	NamedCircle pizza[5];
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
	for (int i = 0; i < 5; i++) {
		cin >> radius[i] >> name[i];
		pizza[i].setRadius(radius[i]);
		pizza[i].setName(name[i]);
	}
	cout << "가장 면적이 큰 피자는 " << largest(pizza, 5) << "입니다." << endl;
}