#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ifstream fin("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\system.ini");
	ofstream fout("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\system.txt");
	if (!fin) {
		cout << "파일 오류" << endl;
		return 0;
	}
	int ch;
	while (true) {
		ch = fin.get();
		if (ch == EOF) {
			break;
		}
		fout.put(toupper(ch));
	}
	
	fin.close();
	fout.close();
}