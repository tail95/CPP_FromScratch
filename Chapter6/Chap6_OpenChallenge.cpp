#include <iostream>
#include <ctime>
using namespace std;

class Person {
	string name;
public:
	void setName(string name) { this->name = name; }
	string getName() { return this->name; }
};

class UpAndDownGame {
	static Person* players;
public:
	static void start() { 
		cout << "Up & Down 게임을 시작합니다." << endl; 
		srand((unsigned)time(0));
		players[0].setName("김인수");
		players[1].setName("오인경");
	}
	static void play(int lower = 0, int upper = 99) {
		int number = rand() % (upper - lower + 1) + lower;
		int predict;
		bool flag = true;
		while (flag) {
			for (int i = 0; i < 2; i++) {
				cout << lower << "과 " << upper << "사이에 있습니다." << endl;
				cout << players[i].getName() << ">>";
				cin >> predict;
				if (number == predict) {
					cout << players[i].getName() << "승리 !" << endl;
					flag = false;
					break;
				}
				else if (number > predict) {
					lower = predict;
				}
				else if (number < predict) {
					upper = predict;
				}
			}
		}
	}
};

Person* UpAndDownGame::players = new Person[2];

int main() {
	UpAndDownGame::start();
	UpAndDownGame::play();
}