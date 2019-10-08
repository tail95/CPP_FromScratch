#include <iostream>
using namespace std;
static void show(int arr[], int size);
class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size) {
		int* result = new int[size*2];
		for (int i = 0; i < size*2; i++) {
			if (i < size) { result[i] = s1[i]; }
			else if (i >= size) { result[i] = s2[i - size]; }
		}
		return result;
	}
	static int* remove(int s1[], int s2[], int size, int& retSize) {
		retSize = size;
		int* result = new int[size];
		for (int i = 0; i < size; i++) {
			result[i] = s1[i];
		}
		for (int i = 0; i < size; i++) {
			cout << i << endl;
			show(s1, retSize);
			for (int j = 0; j < size; j++) {
				if (s2[i] == s1[j]) {
					for (int k = j; k < size - 1; k++) {
						result[k] = result[k + 1];
					}
					retSize--;
				}
			}
		}
		if (retSize == 0) return NULL;
		else return result;
	}
	
};
static void show(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main() {
	int x[5], y[5];
	cout << "정수 5개 입력. 배열 x에 삽입 >>";
	for (int i = 0; i < 5; i++) cin >> x[i];
	cout << "정수 5개 입력. 배열 y에 삽입 >>";
	for (int i = 0; i < 5; i++) cin >> y[i];
	
	int* concat, * remove;
	int remain = 0;

	cout << "합친 정수 배열 출력" << endl;
	concat = ArrayUtility2::concat(x, y, 5);
	show(concat, 10);
	
	remove = ArrayUtility2::remove(x, y, 5, remain);
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는" << remain << endl;
	show(remove, remain);
}