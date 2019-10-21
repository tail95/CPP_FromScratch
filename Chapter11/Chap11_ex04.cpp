#include<iostream>
using namespace std;

int main() {
	int ch;
	while ((ch=cin.get())!=EOF) {
		if (ch != ';') cout << char(ch);
		if (ch == ';') {
			cout << endl;
			cin.ignore(100, '\n');
		}
	}
}