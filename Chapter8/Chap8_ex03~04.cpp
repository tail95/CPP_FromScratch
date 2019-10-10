#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x=0, int y=0, string color="BLACK") : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { this->move(x, y); }
	void setColor(string color) { this->color = color; }
	void show() { cout << this->color << "색으로 (" << this->getX() << ", " << this->getY() << ")에 위치한 점입니다." << endl; }
};

int main() {
	//3
	ColorPoint cp1(5, 5, "RED");
	cp1.setPoint(10, 20);
	cp1.setColor("BLUE");
	cp1.show();
	cout << endl;

	//4
	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp2(5, 5);
	cp2.setPoint(10, 20);
	cp2.setColor("BLUE");
	cp2.show();
}