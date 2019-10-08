#include <iostream>
using namespace std;

//int add(int numbers[], int size) {
//	int sum = 0;
//	for (int i = 0; i < size; i++) {
//		sum += numbers[i];
//	}
//	return sum;
//}
int add(int fnumbers[], int size, int snumbers[]=nullptr) {
	int sum = 0;
	if (snumbers == nullptr) {
		for (int i = 0; i < size; i++) {
			sum += fnumbers[i];
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			sum += fnumbers[i] + snumbers[i];
		}
	}
	
	return sum;
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;
}