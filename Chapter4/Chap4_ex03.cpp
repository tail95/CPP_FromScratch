#include <iostream>
#include <string>
using namespace std;

int main() {
	string texts;
	int start_index = -1, count1 = 0, count2 = 0;

	cout << "문자열 입력>>";
	getline(cin, texts);
	
	//(1)
	for (int i = 0; i < texts.length(); i++) {
		if (texts[i] == 'a') count1++;
	}
	
	//(2)
	while (true) {
		start_index = texts.find('a', start_index+1);
		if (start_index == -1) break;
		count2++;
	}
	cout << "문자 a는 " << count1 << "개 있습니다." << endl;
	cout << "문자 a는 " << count2 << "개 있습니다." << endl;
}