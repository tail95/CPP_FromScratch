#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; }
	Accumulator& add(int n) {
		this->value += n;
		return *this;		// 객체 리턴
	}
	int get() { return this->value; }
};


int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get();
}