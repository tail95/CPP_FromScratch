#include <iostream>
#include <string>
using namespace std;

class Oval {
	int width, height;
public:
	Oval();
	Oval(int w, int h);
	~Oval();
	void set(int w, int h);
	void show();
	int getWidth();
	int getHeight();
};
Oval::Oval() {
	this->width = 1;
	this->height = 1;
}
Oval::Oval(int w, int h) {
	this->width = w;
	this->height = h;
}
Oval::~Oval() {
	cout << "Oval 소멸 : width = " << this->width << ", height = " << this->height << endl;
}
void Oval::set(int w, int h) {
	this->width = w;
	this->height = h;
}
void Oval::show() {
	cout << "width = " << this->width << ", height = " << this->height << endl;
}
int Oval::getWidth() {
	return this->width;
}
int Oval::getHeight() {
	return this->height;
}

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;
}
