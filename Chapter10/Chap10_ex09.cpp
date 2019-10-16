#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	int n;
	while(true) {
		cout << "정수를 입력하세요 >> ";
		cin >> n;
		if (n == 0) break;
		v.push_back(n);
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
			sum += v[i];
		}
		cout << "\n평균= " << (double)sum / v.size() << endl;
	}
}