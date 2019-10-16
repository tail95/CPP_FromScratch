#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string n, string c) { nation = n; capital = c; }
	string getNation() { return this->nation; }
	string getCaptial() { return this->capital; }
};
int main() {
	vector<Nation> v;
	v.push_back(Nation("한국", "서울"));
	v.push_back(Nation("네덜란드", "암스테르담"));
	v.push_back(Nation("독일", "베를린"));
	v.push_back(Nation("러시아", "모스크바"));
	v.push_back(Nation("미국", "워싱턴"));
	v.push_back(Nation("베트남", "하노이"));
	v.push_back(Nation("스위스", "베른"));
	v.push_back(Nation("영국", "런던"));
	v.push_back(Nation("태국", "방콕"));
	cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****" << endl;
	
	int n;
	
	string nation;
	string capital;
	
	while (true) {
		cout << "정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";
		cin >> n;
		switch (n) {
		case 1:
			cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
			cout << "나라와 수도를 입력하세요(no no 이면 입력 끝)" << endl;
			while (true) {
				bool exist = false;
				cout << v.size() + 1 << ">>";
				cin >> nation >> capital;
				if (nation == "no" && capital == "no") break;
				for (int i = 0; i < v.size(); i++) {
					if (v[i].getNation() == nation && v[i].getCaptial() == capital) {
						cout << "already exists !!" << endl;
						exist = true;
						break;
					}
				}
				if(!exist) v.push_back(Nation(nation, capital));
			}
			break;
		case 2:
			srand((unsigned)time(0));
			while (true) {
				int num = rand() % v.size();
				cout << v[num].getNation() << "의 수도는? ";
				cin >> capital;
				if (capital == "exit") break;
				if (v[num].getCaptial() == capital) cout << "Correct !!!" << endl;
				else cout << "NO !!!" << endl;
			}
			break;
		case 3:
			return 0;
		}
	}

}