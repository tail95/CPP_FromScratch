#include<iostream>
using namespace std;

template<class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	T* result= new T[sizeSrc];
	bool checker;
	for (int i = 0; i < sizeSrc; i++) {
		checker = true;
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) {
				checker = false;
				break;
			}
		}
		if (checker) {
			result[retSize] = src[i];
			retSize++;
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
	int src[] = { 1,3,5,7,8,9 };
	int dest[] = { 2,3,4,5,6 };
	int size = 0;
	int* result = remove(src, 6, dest, 5, size);
	show(result, size);

	string ssrc[] = { "안", "녕", "하", "세요" };
	string sdest[] = { "반갑", "하", "세", "요" };
	int ssize = 0;
	string* sresult = remove(ssrc, 4, sdest, 4, ssize);
	show(sresult, ssize);
}