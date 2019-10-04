#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() { name = ""; tel = ""; }
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel) { this->name = name; this->tel = tel; }
};

int main() {
	Person* people = new Person[3];
	string name, tel;
	cout << "이름과 번호를 입력해 주세요" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1 << ">> ";
		cin >> name >> tel;
		people[i].set(name, tel);
	}
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) {
		cout << people[i].getName() << " ";
	}
	cout << "\n전화번호 검색합니다. 이름을 입력하세요 >>";
	cin >> name;
	for (int i = 0; i < 3; i++) {
		if (people[i].getName() == name) {
			cout << people[i].getTel();
			break;
		}
	}
	delete people;
}