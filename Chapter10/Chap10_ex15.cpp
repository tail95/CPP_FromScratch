#include<iostream>
#include<vector>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleManger {
	vector<Circle*> cv;
public:
	CircleManger() { cout << "원을 삽입하고 삭제하는 프로그램입니다. " << endl; }
	int menu() {
		int n;
		cout << "삽입: 1, 삭제: 2, 모두보기: 3, 종료: 4 >>";
		cin >> n;
		return n;
	}
	void insert() {
		int radius;
		string name;
		cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
		cin >> radius >> name;
		cv.push_back(new Circle(radius, name));
	}
	void del() {
		string name;
		cout << "삭제하고자 하는 원의 이름은 >> ";
		cin >> name;
		vector<Circle*>::iterator it;			// iterator 생성
		it = cv.begin();						// 처음값으로 iterator 설정
		for (int i = 0; i < cv.size();i++) {	// 원소를 돌면서
			if (cv[i]->getName()==name)
				it = cv.erase(it);				// 이름이 같을 경우 삭제 (삭제된 원소 다음의 원소에 대한 포인터 리턴)
			else {
				it++;							// 아닐 경우 iterator객체 포인터 증가
			}
		}
	}
	void show() {
		for (int i = 0; i < cv.size(); i++) { cout << cv[i]->getName() << endl; }
	}
	void run() {
		bool flag = true;
		while (flag) {
			switch (menu()) {
			case 1:
				insert();
				break;
			case 2:
				del();
				break;
			case 3:
				show();
				break;
			case 4:
				flag = false;
				break;
			default:
				cout << "잘못된 입력" << endl;
				break;
			}
		}
	}
};

int main() {
	CircleManger cm;
	cm.run();
}