#include <string>
#include <iostream>
using namespace std;

class Console {

public:
	static int menu, flightNum;
	Console() { cout << "***** 한성항공에 오신것을 환영합니다. *****" << endl << endl; }

	//static int flightNum, seatNum;
	void menuSelect() {
		cout << "예약: 1  취소: 2  보기: 3  끝내기: 4>> ";
		cin >> menu;
	}
	void flightSelect() {
		cout << "07시: 1   12시: 2   17시: 3 >>";
		cin >> flightNum;
	}

};

class Seat {
	string name;
public:
	Seat() { this->name = "---"; }
	void reservation(string name) {
		if (this->name != "---") {
			cout << "이미 예약된 좌석입니다." << endl;
		}
		this->name = name;
	}
	void cancel(string name) {
		if (this->name == name) this->name = "---";
	}
	void show() {
		cout << "\t" << this->name;
	}
};



class Schedule {
	Seat* s;
	string flight;
public:
	Schedule() {
		s = new Seat[8];
	}
	~Schedule() { delete[] s; }
	void setName(string f) { this->flight = f; }
	string getName() { return this->flight; }
	void show() {
		cout << this->flight << ":";
		for (int i = 0; i < 8; i++) {
			s[i].show();
		}
		cout << endl;
	}
	void reservation(int seatNumber, string name) {
		s[seatNumber - 1].reservation(name);
	}
	void cancel(int seatNumber, string name) {
		s[seatNumber - 1].cancel(name);
	}
};

int Console::menu = 0;
int Console::flightNum = 0;

class AirlineBook {
	Schedule* sch;
	Console sc;
public:
	AirlineBook() {
		sch = new Schedule[3];
		sch[0].setName("07시");
		sch[1].setName("12시");
		sch[2].setName("17시");
	}
	~AirlineBook() { delete[] sch; }
	void start() {
		while (true) {
			sc.menuSelect();
			if (Console::menu == 1 || Console::menu == 2) {
				sc.flightSelect();
				cout << "FLIGHT NUMBER: " << Console::flightNum - 1<<endl;
				sch[Console::flightNum - 1].show();
				int sn;
				string name;
				cout << "좌석 전호>> "; cin >> sn;
				cout << "이름 입력>> "; cin >> name;
				if (Console::menu == 1) { sch[Console::flightNum - 1].reservation(sn, name); }
				else { sch[Console::flightNum - 1].cancel(sn, name); }
				cout << endl;
			}
			else if (Console::menu == 3) {
				for (int i = 0; i < 3; i++) {
					sch[i].show();
				}
			}
			else if (Console::menu == 4) {
				cout << "예약 시스템을 종료합니다. " << endl;
				return;
			}
		}
	}

};

int main() {
	AirlineBook* ab = new AirlineBook();
	ab->start();
}