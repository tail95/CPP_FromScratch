#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;

	virtual int size() = 0;
};

class IntStack {
	int capacity;
	int top;
	int* p;
public:
	IntStack(int size=100) {
		capacity = size;
		p = new int[capacity];
		top = 0;
	}
	~IntStack() { delete[] p; }
	virtual bool push(int n) {
		if (this->size() == capacity) return false;
		p[top++] = n;
		return true;
	}
	virtual bool pop(int& n) {
		if (this->size() == 0) return false;
		n = p[--top];
		return true;
	}
	virtual int size() {
		return top;
	}
};

int main() {
	IntStack a(5);
	for (int i = 0; i < 10; i++) { // 처음 5 개를 성공적으로 push되고 다음 5 개는 스택 full로 push 실패
		if (a.push(i)) cout << "push 성공" << endl;
		else cout << "스택 full" << endl;
	}

	int n;
	for (int i = 0; i < 10; i++) { // 처음 5 개를 성공적으로 pop되고 다음 5 개는 스택 empty로 pop 실패
		if (a.pop(n)) cout << "pop 성공 " << n << endl;
		else cout << "스택 empty" << endl;
	}
}