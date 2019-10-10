#include <iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) { this->capacity = capacity; mem = new int[capacity]; }
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue :public BaseArray {
	int tail;
	int head;
	int size;
public:
	MyQueue(int capacity) : BaseArray(capacity) { 
		head = 0;
		size = 0;
		tail = -1;
	}
	void enqueue(int n) { 
		if (size == capacity()) return;  //full
		this->put(head, n);
		head = (head+1) % capacity();
		size++;
	}
	int dequeue() {
		if (size == 0) return -1; //empty
		tail = (tail+1) % capacity();
		size--;
		return this->get(tail);
	}
	int capacity() { return this->getCapacity(); }
	int length() { return size; }
	
};

class MyStack :public BaseArray {
	int top;
	int size;
public:
	MyStack(int capacity) : BaseArray(capacity) {
		top = -1;
		size = 0;
	}
	void push(int n) {
		if (size == capacity()) return;  //full
		this->put(++top, n);
		size++;
	}
	int pop() {
		if (size == 0) return -1; //empty
		size--;
		return this->get(top--);
	}
	int capacity() { return this->getCapacity(); }
	int length() { return size; }

};

int main() {
	// 5
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수 입력>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력>> ";
	while (mQ.length() != 0) { cout << mQ.dequeue() << ' '; }
	cout << endl << "큐의 현재 크기: " << mQ.length() << ' ' << endl;
	
	//6
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수 입력>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택 용량: " << mStack.capacity() << ", 스택 크기: " << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력>> ";
	while (mStack.length() != 0) { cout << mStack.pop() << ' '; }
	cout << endl << "큐의 현재 크기: " << mStack.length() << ' ' << endl;
}