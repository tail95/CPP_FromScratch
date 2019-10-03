#include<iostream>
using namespace std;

int main() {
	int total_money = 0, num, money;
	char coffee[20];
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;
	while (total_money < 20000) {
		cout << "주문>> ";
		cin >> coffee >> num;
		if (!strcmp(coffee, "에스프레소")) {
			money = 2000 * num;
		}
		else if (!strcmp(coffee, "아메리카노")) {
			money = 2300 * num;
		}
		else if (!strcmp(coffee, "카푸치노")) {
			money = 2500 * num;
		}
		else {
			cout << "다시 입력";
			continue;
		}
		total_money += money;
		cout << money << "원입니다. 맛있게 드세요." << endl;
	}
	cout << "오늘 " << total_money << "원을 판매하여 카페를 닫습니다. 내일봐요~~~~~~~~~";
}

