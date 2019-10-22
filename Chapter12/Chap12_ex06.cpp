#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ifstream fin("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\system.ini", ios::in | ios::binary);
	ofstream fout("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\system.txt");
	if (!fin) {
		cout << "파일 오류" << endl;
		return 0;
	}
	fin.seekg(0, ios::end);
	long length = fin.tellg();
	int num = length / 10;
	fin.seekg(0, ios::beg);
	char buf[1];
	int count = 0;
	cout << "복사 시작... " << endl;
	while (!fin.eof()) {
		fin.read(buf, 1);
		int n = fin.gcount();
		fout.write(buf, n);
		if (count % num == 0) {
			cout << ". " << num << "B " << count / num * 10 << "%" << endl;
		}
		count += n;

	}
	cout << count << "복사완료" << endl;

	
	fin.close();
}