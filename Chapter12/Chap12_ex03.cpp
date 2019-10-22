#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ifstream fin("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\system.ini");
	if (!fin) {
		cout << "파일 오류" << endl;
		return 0;
	}
	string line;
	int nline = 1;
	while (getline(fin, line)) {
		for (int i = 0; i < line.length(); i++) {
			cout << (char)toupper(line[i]);
		}
		cout << endl;
		nline++;
	}
	
	fin.close();
}