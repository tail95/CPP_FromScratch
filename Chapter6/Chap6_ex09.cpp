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
		cout << "********** �Խ��� �Դϴ�. **********" << endl;
		for (int i = 0; i < num; i++) {
			cout << i << ": " << texts[i] << endl;
		}
		cout << endl;
	}
};

int Board::num = 0;
string* Board::texts = new string[100];

int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �����մϴ�.");
	Board::print();
}