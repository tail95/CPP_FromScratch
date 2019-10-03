#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Date {
	int year, month, day;
public:
	Date(int y, int m, int d);
	Date(string d);
	void show();
	int getYear();
	int getMonth();
	int getDay();
};

Date::Date(int y, int m, int d) {
	this->year = y;
	this->month = m;
	this->day = d;
}
Date::Date(string d) {
	string str_arr[10];
	int str_cnt = 0;
	char* str_buffer = new char[30];
	strcpy(str_buffer, d.c_str());
	char* tok = strtok(str_buffer, "/");
	while (tok != nullptr) {
		str_arr[str_cnt++] = string(tok);
		tok = strtok(nullptr, "/");
	}
	this->year = stoi(str_arr[0]);
	this->month = stoi(str_arr[1]);
	this->day = stoi(str_arr[2]);
}
void Date::show() {
	cout << this->year << "년" << this->month << "월" << this->day << "일" << endl;
}
int Date::getYear() {
	return this->year;
}
int Date::getMonth() {
	return this->month;
}
int Date::getDay() {
	return this->day;
}


int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}