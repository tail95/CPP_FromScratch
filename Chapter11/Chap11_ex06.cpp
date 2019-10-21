#include<iostream>
#include<cmath>
using namespace std;

int main() {
	cout.setf(ios::left);
	cout.width(15);
	cout << "Number";
	cout.width(15);
	cout << "Square";
	cout.width(15);
	cout << "Square Root" << endl;
	for (int i = 0; i < 10; i++) {
		int number = i * 5;
		cout.fill('_');
		cout.width(15);
		cout << number;
		cout.fill('_');
		cout.width(15);
		cout << number*number;
		cout.fill('_');
		cout.width(15);
		cout.precision(3);
		cout << (float)sqrt(number) << endl;

	}
}

//#include <iostream>
//#include <iomanip>
//#include <cmath>
//using namespace std;
//
//int main() {
//	cout << left;
//	cout << setw(15) << "Number";
//	cout << setw(15) << "Square";
//	cout << setw(15) << "Square Root" << endl;
//	for (int i = 0; i < 50; i += 5) {
//		cout << setw(15) << setfill('_') << dec << i;
//		cout << setw(15) << setfill('_') << dec << i * i;
//		cout << setw(15) << setfill('_') << dec << setprecision(3) << sqrt((double)i) << endl;
//	}
//}