#include<iostream>
#include<map>
using namespace std;

class ScoreManager {
	map<string, int> ma;
public:
	ScoreManager() { cout << "***** 점수 관리 프로그램 HIGH SCORE 시작합니다. *****" << endl; }
	void run() {
		int m;
		while (true) {
			string name;
			int score;
			cout << "입력: 1, 조회: 2, 종료: 3 >> ";
			cin >> m;
			if (m == 1) {
				cout << "이름과 점수>> ";
				cin >> name >> score;
				ma.insert(make_pair(name, score));
			}
			else if (m == 2) {
				cout << "이름>> ";
				cin >> name;
				cout << name << "의 점수는 " << ma[name] << endl;
			}
			else {
				cout << "프로그램을 종료합니다... " << endl;
				break;
			}
		}
	}
};

int main() {
	ScoreManager sm;
	sm.run();
}