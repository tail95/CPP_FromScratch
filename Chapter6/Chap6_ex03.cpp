#include <iostream>
using namespace std;
//int big(int a, int b) {
//	int big = a > b ? a : b;
//	if (big > 100) return 100;
//	else return big;
//}
//int big(int a, int b, int m) {
//	int big = a > b ? a : b;
//	if (big > m) return m;
//	else return big;
//}
int big(int a, int b, int m = 100) {
	int big = a > b ? a : b;
	if (big > m) return m;
	else return big;
}
int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
}