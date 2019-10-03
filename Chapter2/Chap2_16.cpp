/*
Wise men say, only fools rush in
But I can't help, falling in love with you

Shall I stay ? Would it be a sin ?
If I can't help, falling in love with you

Like a river flows, surely to the sea
Darling so it goes, some things aren't meant to be ;
*/

#include<iostream>
using namespace std;

int main() {
	char buffer[10000];
	int alpha[26] = { 0, };
	int i = 0, count =0;
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;
	cin.getline(buffer, 10000, ';');
	while (buffer[i] != '\0') {
		if (isalpha(buffer[i])) {
			count++;
			alpha[(int)(tolower(buffer[i]) - 97)]++;
			i++;
		}
	}
	cout << "총 알파벳 수 " << count << endl;
	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 97) << " (" << alpha[i] << ")\t" << ": ";
		for (int j = 0; j < alpha[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

