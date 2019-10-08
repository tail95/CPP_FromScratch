#include <iostream>

using namespace std;

class Matrix {
	int arr[4];
public:
	Matrix() { for (int i = 0; i < 4; i++)arr[i] = 0; }
	Matrix(int a, int b, int c, int d) { arr[0] = a; arr[1] = b; arr[2] = c; arr[3] = d; }
	//Matrix& operator >>(int numbers[]) {
	//	for (int i = 0; i < 4; i++) {
	//		numbers[i] = this->arr[i];
	//	}
	//	return *this;
	//}
	//Matrix& operator <<(int numbers[]) {
	//	for (int i = 0; i < 4; i++) {
	//		this->arr[i] = numbers[i];
	//	}
	//	return *this;
	//}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++) {
			cout << this->arr[i] << ' ';
		}
		cout << "}" << endl;
	}
	friend Matrix& operator >>(Matrix& A, int numbers[]);
	friend Matrix& operator <<(Matrix& A, int numbers[]);
};

Matrix& operator >>(Matrix& A, int numbers[]) {
	for (int i = 0; i < 4; i++) {
		numbers[i] = A.arr[i];
	}
	return A;
}
Matrix& operator <<(Matrix& A, int numbers[]) {
	for (int i = 0; i < 4; i++) {
		A.arr[i] = numbers[i];
	}
	return A;
}
int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;
	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}