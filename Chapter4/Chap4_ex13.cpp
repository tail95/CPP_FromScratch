#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string text;
public:
	Histogram(string text) { this->text = text + "\n"; }
	void put(string t) { this->text.append(t); }
	void putc(char c) { this->text.append(string(1,c)); }
	void print() { 
		int count = 0;
		cout << text << endl; 
		int alpha[26] = { 0, };
		for (int i = 0; i < text.length(); i++) {
			if (isalpha(text[i])) {
				count++;
				char w = tolower(text[i]);
				alpha[(int)w - 97]++;
			}
		}
		cout << "총 알파벳 수 " << count << endl;
		for (int i = 0; i < 26; i++) {
			cout << (char)(i+97) << "(" << alpha[i] << ")\t: ";
			for (int j = 0; j < alpha[i]; j++) cout << "*";
			cout << endl;
		}
	}
};

int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}