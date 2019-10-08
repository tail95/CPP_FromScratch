#include <iostream>

using namespace std;

class Statistics {
	int* numbers;
	int index;
public:
	Statistics() { numbers = new int[10]; index = 0; }
	bool operator !() { return index == 0 ? true : false; }
	Statistics& operator << (int num) {
		numbers[this->index++] = num;
		return *this;
	}
	void operator ~() { 
		for (int i = 0; i < index; i++) {
			cout << numbers[i] << " ";
		}
		cout << endl;
	}
	int operator >>(int& avg) {
		int sum = 0;
		for (int i = 0; i < index; i++) {
			sum += numbers[i];
		}
		avg = sum / index;
		return avg;
	}

};

int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다. " << endl;

	int x[5];
	cout << "5개의 정수를 입력하라 >> ";
	for (int i = 0; i < 5; i++)cin >> x[i];

	for (int i = 0; i < 5; i++)stat << x[i];
	
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg= " << avg << endl;
}