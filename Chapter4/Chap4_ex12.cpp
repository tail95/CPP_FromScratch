#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; }
	double getArea() { return 3.141592 * this->radius * this->radius; }
	string getName() { return this->name; }
};

class CircleManager {
	Circle* p;
	int size;
public:
	CircleManager(int size) {
		this->size = size;
		p = new Circle[this->size];
		string name;
		int radius;
		for (int i = 0; i < this->size; i++) {
			cout << "원 " << i + 1 << "이름과 반지름 >> ";
			cin >> name >> radius;
			p[i].setCircle(name, radius);
		}
	}
	~CircleManager() {
		delete[] p;
	}
	void searchByName(string name) {
		for (int i = 0; i < this->size; i++) {
			if (p[i].getName() == name) {
				cout << p[i].getName() << "의 면적은 " << p[i].getArea();
			}
		}
		cout << endl;
	}
	void searchByArea(int area) {
		for (int i = 0; i < this->size; i++) {
			if (p[i].getArea() > area) {
				cout << p[i].getName() << "의 면적은 " << p[i].getArea() << '\t';
			}
		}
		cout << endl;
	}
};

int main() {
	int num;
	cout << "원의 개수 >> ";
	cin >> num;
	
	CircleManager cm(num);

	string name;
	cout << "검색하고자 하는 원의 이름  >> ";
	cin >> name;
	cm.searchByName(name);

	int area;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> area;
	cm.searchByArea(area);

	
}