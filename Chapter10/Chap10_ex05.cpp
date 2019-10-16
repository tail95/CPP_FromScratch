#include<iostream>
using namespace std;

template<class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
	int size = sizea + sizeb;
	T* result;
	result = new T[size];
	for (int i = 0; i < size; i++) {
		if (i < sizea) {
			result[i] = a[i];
		}
		else {
			result[i] = b[i - sizea];
		}
	}
	return result;
}

template<class T>
void show(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10,11,12 };
	int* c = concat(a, 5, b, 7);
	show(c, 12);

	char d[] = { 'a', 'b', 'c', 'E' };
	char e[] = { 'g', 'Z', 'F' };
	char* f = concat(d, 4, e, 3);
	show(f, 7);
}