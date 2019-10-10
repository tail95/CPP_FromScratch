#include <iostream>
using namespace std;

class SortedArray {
	int size;
	int* p;
	void sort();
public:
	SortedArray();
	SortedArray(SortedArray& src);
	SortedArray(int p[], int size);
	~SortedArray();
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2);
	void show();
};
void SortedArray::sort() {
	int tmp;
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = 0; j < this->size - 1; j++) {
			if (this->p[j] > this->p[j + 1]) {
				tmp = p[j + 1];
				p[j + 1] = p[j];
				p[j] = tmp;
			}
		}
	}
}
SortedArray::SortedArray() {
	this->size = 0;
	this->p = NULL;
}
SortedArray::SortedArray(SortedArray& src) {
	this->size = src.size;
	this->p = new int[this->size];
	for (int i = 0; i < this->size; i++) { this->p[i] = src.p[i]; }
}
SortedArray::SortedArray(int p[], int size) {
	this->size = size;
	this->p = new int[this->size];
	for (int i = 0; i < this->size; i++) {
		this->p[i] = p[i];
	}
}
SortedArray::~SortedArray() { if (p) delete[] p; }
SortedArray SortedArray::operator + (SortedArray& op2) {
	SortedArray result;
	result.size = this->size + op2.size;
	result.p = new int[result.size];
	int i = 0;
	for (int j = 0; j < this->size; j++) { result.p[i] = this->p[j]; i++; }
	for (int j = 0; j < op2.size; j++) { result.p[i] = op2.p[j]; i++; }
	return result;
}
SortedArray& SortedArray::operator = (const SortedArray& op2) {
	this->size = op2.size;
	this->p = new int[this->size];
	for (int i = 0; i < this->size; i++) { this->p[i] = op2.p[i]; }
	return *this;
}
void SortedArray::show() {
	this->sort();
	cout << "배열 출력 : ";
	for (int i = 0; i < this->size; i++) {
		cout << p[i] << ' ';
	}
	cout << endl;
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;
	c = a + b;
	a.show();
	b.show();
	c.show();
}