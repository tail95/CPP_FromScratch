#include <iostream>

using namespace std;

class Matrix {
	int arr[4];
public:
	Matrix() { for (int i = 0; i < 4; i++)arr[i] = 0; }
	Matrix(int a, int b, int c, int d) { arr[0] = a; arr[1] = b; arr[2] = c; arr[3] = d; }
	//Matrix operator + (Matrix A) {
	//	Matrix tmp;
	//	for (int i = 0; i < 4; i++) {
	//		tmp.arr[i] = this->arr[i] + A.arr[i];
	//	}
	//	return tmp;
	//}
	//Matrix& operator +=(Matrix A) {
	//	for (int i = 0; i < 4; i++) {
	//		this->arr[i] += A.arr[i];
	//	}
	//	return *this;
	//}
	//bool operator ==(Matrix A) {
	//	bool flag = true;
	//	for (int i = 0; i < 4; i++) {
	//		if (this->arr[i] != A.arr[i]) flag = false;
	//	}
	//	return flag;
	//}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++) {
			cout << this->arr[i] << ' ';
		}
		cout << "}" << endl;
	}
	friend Matrix operator + (Matrix A, Matrix B);
	friend Matrix& operator +=(Matrix& A, Matrix B);
	friend bool operator ==(Matrix A, Matrix B);
};

Matrix operator +(Matrix A, Matrix B) {
	Matrix tmp;
	for (int i = 0; i < 4; i++) {
		tmp.arr[i] = A.arr[i] + B.arr[i];
	}
	return tmp;
}
Matrix& operator +=(Matrix& A, Matrix B) {
	for (int i = 0; i < 4; i++) {
		A.arr[i] += B.arr[i];
	}
	return A;
}
bool operator ==(Matrix A, Matrix B) {
	bool flag = true;
	for (int i = 0; i < 4; i++) {
		if (A.arr[i] != B.arr[i]) flag = false;
	}
	return flag;
}
int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c) cout << "a and c are the same" << endl;
}