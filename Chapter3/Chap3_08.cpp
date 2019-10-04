#include <iostream>
#include <string>
using namespace std;

class Integer {
	int number;
public:
	Integer(int num);
	Integer(string num);
	int get();
	void set(int num);
	bool isEven();
};

Integer::Integer(int num) {
	this->number = num;
}
Integer::Integer(string num) {
	this->number = stoi(num);
}
int Integer::get() {
	return this->number;
}
void Integer::set(int num) {
	this->number = num;
}
bool Integer::isEven() {
	return this->number % 2 == 0 ? true : false;
}
int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();
}