#include <iostream>
#include <string>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {	size = n; p = new int[n];}
	void read() {
		for (int i = 0; i < size; i++) {
			cin >> p[i];
		}
	}
	void write() {
		for (int i = 0; i < size; i++) {
			cout << p[i] << ' ';
		}
		cout << endl;
	}
	int big() {
		int max = INT_MIN;
		for (int i = 0; i < size; i++) {
			if (max < p[i]) {
				max = p[i];
			}
		}
		return max;
	}
	~Sample() {
		delete p;
	}
};

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;
}