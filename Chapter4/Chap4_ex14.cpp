#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Player {
	string name;
public:
	Player() { this->name = ""; }
	void setName(string name) { this->name = name; }
	string getName() { return this->name; }
};
class GamblingGame {
	Player* players;
public:
	GamblingGame();
	~GamblingGame();
	void play();
};
GamblingGame::GamblingGame() {
	string name[2];
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	cout << "첫번째 선수 이름>>";
	cin >> name[0];
	cout << "두번째 선수 이름>>";
	cin >> name[1];
	players = new Player[2];
	for (int i = 0; i < 2; i++) {
		players[i].setName(name[i]);
	}
}
GamblingGame::~GamblingGame() {
	delete[] players;
}
void GamblingGame::play() {
	int numbers[3];
	string tmp;
	bool flag = false;
	while (!flag) {
		for (int i = 0; i < 2; i++) {
			cout << players[i].getName() << ":<Enter>" << endl;
			getline(cin, tmp);
			for (int j = 0; j < 3; j++) {
				numbers[j] = rand() % 3;
				cout << '\t' << numbers[j];
			}
			cout << '\t';
			if (numbers[0] == numbers[1] && numbers[1] == numbers[2]) {
				cout << players[i].getName() << "님 승리 !!" << endl;
				flag = true;
				break;
			}
			else {
				cout << "아쉽군요!" << endl;
			}
		}

	}
}

int main() {
	srand((unsigned)time(0));
	GamblingGame gg;
	gg.play();
}