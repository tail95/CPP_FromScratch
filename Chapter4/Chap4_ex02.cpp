#include <iostream>
using namespace std;

int main() {
	int* integers = new int[5];
	int sum = 0;
	cout << "정수 5개 입력>>";
	for (int i = 0; i < 5; i++) {
		cin >> integers[i];
		sum += integers[i];
	}
	cout << "평균 " << (double)sum / 5 << endl;
}