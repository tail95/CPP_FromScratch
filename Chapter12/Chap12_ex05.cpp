#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ifstream fin("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\ShowNoComment.cpp");
	if (!fin) {
		cout << "파일 오류" << endl;
		return 0;
	}
	string line;
	while (getline(fin, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '/' && line[i + 1] == '/') break;
			cout << line[i];
		}
		cout << endl;
	}
	
	fin.close();
}