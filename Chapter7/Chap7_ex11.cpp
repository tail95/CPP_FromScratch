#include <iostream>
using namespace std;

class Stack {
	int* stack;
	int size;
	int top;
public:
	Stack(int size=100) {
		this->size = size;
		this->stack = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			this->stack[i] = 0;
		}
		this->top = -1;
	}
	Stack& operator <<(int x) {
		stack[++top] = x;
		return *this;
	}
	bool operator !() {
		return this->top == -1 ? true : false;
	}
	Stack& operator >>(int& x) {
		x = stack[top--];
		return *this;
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << stack[i] << ' ';
		}
	}
};


int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x; 
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}