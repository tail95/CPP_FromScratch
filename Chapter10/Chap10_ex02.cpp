#include<iostream>
using namespace std;

template <class T>
bool equalArrays(T arrX[], T arrY[], int size) {
	for (int i = 0; i < size; i++) { if (arrX[i] != arrY[i]) return false; }
	return true;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4 };
	if (equalArrays(x, y, 5)) cout << "같다";
	else cout << "다르다";
}