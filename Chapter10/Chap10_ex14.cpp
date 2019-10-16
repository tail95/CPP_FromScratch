#include<iostream>
#include<map>
using namespace std;

class SecurityManger {
	map<string, string> m;
public:
	SecurityManger() { cout << "***** 암호 관리 프로그램 WHO를 시작합니다. *****" << endl; }
	void run() {
		int n;
		while (true) {
			string name;
			string password;
			cout << "삽입: 1, 검사: 2, 종료: 3 >> ";
			cin >> n;
			if (n == 1) {
				cout << "이름 암호>> ";
				cin >> name >> password;
				m.insert(make_pair(name, password));
			}
			else if (n == 2) {
				cout << "이름? "; cin >> name;
				while (true) {
					cout << "암호? "; cin >> password;
					if (m[name] == password) {
						cout << "통과!" << endl;
						break;
					}
					else cout << "실패~~" << endl;
				}
			}
			else {
				cout << "프로그램을 종료합니다... " << endl;
				break;
			}
		}
	}
};

int main() {
	SecurityManger sm;
	sm.run();
}