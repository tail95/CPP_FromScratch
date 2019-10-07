#include <iostream>
using namespace std;

class MyIntStack {
	int* p;
	int size;
	int tos;
public:
	MyIntStack();
	MyIntStack(int size);
	MyIntStack(MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack::MyIntStack() {
	this->size = 1;
	this->p = new int[this->size];
	this->tos = -1;
}

MyIntStack::MyIntStack(int size) {
	this->size = size;
	this->p = new int[this->size];
	this->tos = -1;
}

MyIntStack::MyIntStack(MyIntStack& s) {		// 복사생성자
	this->size = s.size;
	this->tos = s.size;
	this->p = new int[this->size];				// 깊은 복사를 위해 동적할당
	for (int i = 0; i < size; i++) {
		this->p[i] = s.p[i];
	}
}

MyIntStack::~MyIntStack() {
	delete p;
}

bool MyIntStack::push(int n) {
	if (tos != size-1) {
		p[++tos] = n;
		return true;
	}
	else return false;
}

bool MyIntStack::pop(int& n) {
	if (tos != -1) {
		n = p[tos--];
		return true;
	}
	else return false;
}
int main() {
	MyIntStack a(8);
	a.push(10);
	a.push(20);
	MyIntStack b = a;
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
}