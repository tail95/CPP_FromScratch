#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

class Book {
	int year;
	string title;
	string author;
public:
	Book() {}
	void import(int y, string t, string a) { year = y; title = t; author = a; }
	int getYear() { return year; }
	string getTitle() { return title; }
	string getAuthor() { return author; }
	void show() { cout << getYear() << "년도, " << getTitle() << ", " << getAuthor() << endl; }
};
int main() {
	vector<Book> v;
	int n;
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다. " << endl;
	while (true) {
		int year;
		string title, author;
		cout << "년도>> "; cin >> year;
		if (year == -1) break;
		cout << "책이름>> "; cin >> title;
		cout << "저자>> "; cin >> author;
		Book b = Book();
		b.import(year, title, author);
		v.push_back(b);
	}
	int year;
	string author;
	cout << "총 입고된 책은 " << v.size() << "권 입니다." << endl;
	cout << "검색하고자 하는 저자 이름을 입력하세요>> "; cin >> author;
	for (int i = 0; i < v.size(); i++) { if (author == v[i].getAuthor()) { v[i].show(); } }
	cout << "검색하고자 하는 년도를 입력하세요>> "; cin >> year;
	for (int i = 0; i < v.size(); i++) { if (year == v[i].getYear()) { v[i].show(); } }
}