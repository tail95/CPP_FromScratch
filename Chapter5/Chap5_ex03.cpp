#include <iostream>
#include <string>
using namespace std;

void combine(string txt1, string txt2, string& txt3) {
	txt3 = txt1 + " " + txt2;
}
int main() {
	string text1("I love you"), text2("very much");
	string text3;
	combine(text1, text2, text3);
	cout << text3;
}