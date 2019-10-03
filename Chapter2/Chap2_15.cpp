#include<iostream>
using namespace std;

int main() {
	int a, b, result;
	char op;
	while (true) {
		cout << "? ";
		cin >> a >> op >> b;
		if (op == '+') result = a + b;
		else if (op == '-') result = a - b;
		else if (op == '*') result = a * b;
		else if (op == '/') result = a / b;
		else if (op == '%')	result = a % b;
		else continue;
		cout << a << " " << op << " " << b << " = " << result << endl;
	}
}

