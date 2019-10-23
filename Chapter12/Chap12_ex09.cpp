#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main() {
	ifstream fin("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\system.ini", ios::in);
	
	if (!fin) {
		cout << "파일 오류" << endl;
		return 0;
	}
	cout << "system.ini 읽기 완료" << endl;
	cout << "라인 번호 입력" << endl;
	int line;
	vector<string> v;
	string s;
	while (getline(fin, s)) {
		v.push_back(s);
	}
	while (true) {
		cout << " ---> ";
		cin >> line;
		if (line < 1) {
			cout << "종료합니다." << endl;
			break;
		}
		if (line > v.size())continue;
		cout << v[line - 1] << endl;
	}
}