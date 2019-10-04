#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
public:
	Player() {}
	void setName(string n) { this->name = n; }
	string getName() { return this->name; }
};
// Player를 위에 선언해줘야 WordGame에서 오류 발생 X
class WordGame {
	int num_players;
	Player *player;
public:
	WordGame() {
		cout << "끝말 잇기 게임을 시작합니다\n게임에 참가하는 인원은 몇명입니까?"; 
		cin >> num_players;
		this->num_players = num_players;
		player = new Player[this->num_players];
	}
	~WordGame() { delete[] player; }
	void start() {
		for (int i = 0; i < this->num_players; i++) {
			string name;
			cout << "참가자의 이름을 입력하세요. 빈칸 없이 >>";
			cin >> name;
			player[i].setName(name);
		}
		cout << "시작하는 단어는 아버지 입니다." << endl;
		string word = "아버지";
		string nextWord;
		bool flag = true;
		while (flag) {
			for (int i = 0; i < num_players; i++) {
				cout << player[i].getName() << ">>";
				cin >> nextWord;
				if (word[word.length() - 2] == nextWord[0] && word[word.length() - 1] == nextWord[1]) {
					word = nextWord;
				}
				else {
					cout << "실패";
					flag = false;
					break;
				}
			}
		}
	}
};

int main() {
	WordGame wg;
	wg.start();
}