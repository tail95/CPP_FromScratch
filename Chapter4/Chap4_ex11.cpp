#include <iostream>
#include <string>
using namespace std;

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { this->size = 10; }
	void consume() { this->size--; }
	int getSize() { return this->size; }
};

class coffeeVendingMachine {
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
public:
	coffeeVendingMachine();
	void run();
};
coffeeVendingMachine::coffeeVendingMachine() {
	fill();
}
void coffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	}
}
void coffeeVendingMachine::selectEspresso() {
	tong[0].consume();
	tong[1].consume();
	cout << "에스프레소 드셈" << endl;
}
void coffeeVendingMachine::selectAmericano() {
	tong[0].consume();
	tong[1].consume(); tong[1].consume();
	cout << "아메리카노 드셈" << endl;
}
void coffeeVendingMachine::selectSugarCoffee() {
	tong[0].consume();
	tong[1].consume(); tong[1].consume();
	tong[2].consume();
	cout << "설탕커피 드셈" << endl;
}
void coffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ",물 " << tong[1].getSize() << ",설탕 " << tong[2].getSize() << endl;
}
void coffeeVendingMachine::run() {
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	int menuNum;
	while (true) {
		cout << "메뉴를 눌러주세요 (1: 에스프레소, 2: 아메리카노, 3: 설탕커피, 4: 잔량보기, 5: 채우기)>> ";
		cin >> menuNum;
		switch (menuNum) {
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		default:
			cout << "다른 번호 선택";
			break;
		}
	}
}

int main() {
	coffeeVendingMachine cvm;
	cvm.run();
}