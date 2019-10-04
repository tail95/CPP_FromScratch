#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
	string text;
	cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다.)" << endl;
	srand((unsigned)time(0));
	while (true) {
		cout << ">>";
		getline(cin, text);
		if (text == "exit") break;
		int pos = rand() % text.length();
		int n = (char)(rand() % 26 + 97);
		text.replace(pos, 1, string(1,n));
		cout << text << endl;
	}
}