#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("C:\\Users\\BH\\Desktop\\gittest\\CPP_FS\\Chapter12\\ShowNoComment.cpp");
	if(!fin) {
		cout <<"ShowNoComment.cpp ���� ����";
		return 0;
	}
	int ch;
	bool found=false;
	while((ch=fin.get()) != EOF) {
		if(ch == '/') {
			if(found == false) 
				found = true; // ������ �Ѱ� �߰�. �ּ� ���� ����
			else { // ���ӵ� �� ���� // �߰�
				fin.ignore(100,'\n'); // '\n'�� ���� ������ 100���� ���� ����
				cout.put('\n');
				found = false; // �ּ� ���� �Ϸ�
			}
		}
		else {
			if(found == true) { // �����ð� �� �� ���� ���ڷ� �ִ� ���
				cout << "/"; // '/'�� �߰ߵ� ���� ���ӵ� '/'�� ���� ������ ������ '/' ���
				found = false; // �ּ� ���� Ŭ����
			}
			cout.put(ch); /
		}
	}

	fin.close();
}