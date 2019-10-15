#include<iostream>
using namespace std;

template <class T>
T biggest(T arr[], int size) {
	T bigge = arr[0];
	for (int i = 1; i < size; i++) {
		if (bigge < arr[i]) bigge = arr[i];
	}
	return bigge;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	cout << biggest(x, 5) << endl;
	double y[] = { 2.4, 9.1, 11.11, 5, 3 };
	cout << biggest(y, 5) << endl;
}