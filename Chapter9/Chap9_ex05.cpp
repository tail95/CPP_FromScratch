#include <iostream>
using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	virtual bool operation() { return this->x & this->y; }
};

class ORGate : public AbstractGate {
public:
	virtual bool operation() { return this->x | this->y; }
};

class XORGate : public AbstractGate {
public:
	virtual bool operation() { return this->x ^ this->y; }
};
int main() {
	ANDGate andGate;
	ORGate orGate;
	XORGate xorGate;

	andGate.set(true, false);
	orGate.set(true, false);
	xorGate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << andGate.operation() << endl;
	cout << orGate.operation() << endl;
	cout << xorGate.operation() << endl;
}