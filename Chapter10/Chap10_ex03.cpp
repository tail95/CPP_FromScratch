#include<iostream>
using namespace std;

template <class T>
void reverseArray(T* arr, int size) {
	T tmp;
	for (int i = 0; i < size / 2; i++) {
		tmp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = tmp;
	}
}

int main() {
	int x[] = { 1,10,100,5,4,6 };
	reverseArray(x, 6);
	for (int i = 0; i < 6; i++)cout << x[i] << ' ';
}