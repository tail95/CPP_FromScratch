#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a == b)return true;
	else {
		big = a > b ? a : b;
		return false;
	}
}
int main() {
	int a, b, big;
	cout << "두 정수를 입력하세요.";
	cin >> a >> b;
	b = bigger(a, b, big);
	if (b) cout << "같습니다" << endl;
	else cout << "큰수는 " << big << "입니다." << endl;
}