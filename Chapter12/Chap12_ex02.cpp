#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ifstream fin("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\system.ini");
	if (!fin) {
		cout << "���� ����" << endl;
		return 0;
	}
	string line;
	int nline = 1;
	while (getline(fin, line)) {
		cout << nline << ": " << line << endl;
		nline++;
	}

	fin.close();
}