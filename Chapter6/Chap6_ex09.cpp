#include <iostream>
using namespace std;

class Board {
	static string* texts;
	static int num;
public:
	static void add(string text) {
		texts[num] = text;
		num++;
	}
	static void print() {
		cout << "********** 게시판 입니다. **********" << endl;
		for (int i = 0; i < num; i++) {
			cout << i << ": " << texts[i] << endl;
		}
		cout << endl;
	}
};

int Board::num = 0;
string* Board::texts = new string[100];

int main() {
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하합니다.");
	Board::print();
}