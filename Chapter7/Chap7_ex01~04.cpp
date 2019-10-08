#include <iostream>
#include <string>
using namespace std;


class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	//Book& operator +=(int price) {
	//	this->price += price;
	//	return *this;
	//}
	//Book& operator -=(int price) {
	//	this->price -= price;
	//	return *this;
	//}
	//bool operator == (int n) {
	//	if (this->price == n) return true;
	//	else return false;
	//}
	//bool operator == (string title) {
	//	if (this->title == title) return true;
	//	else return false;
	//}
	//bool operator == (Book b) {
	//	if (this->title == b.title && this->price == b.price && this->pages == b.pages) return true;
	//	else return false;
	//}
	bool operator ! () { return this->price == 0 ? true : false; }
	friend Book& operator += (Book& b, int price);
	friend Book& operator -= (Book& b, int price);
	friend bool operator == (Book b, int price);
	friend bool operator == (Book b, string title);
	friend bool operator == (Book b1, Book b2);
	friend bool operator < (string s, Book b);
	void show() {
		cout << title << ' ' << price << "원 " << pages << "페이지" << endl;
	}
	string getTitle() { return title; }
};
Book& operator += (Book& b, int price) {
	b.price += price;
	return b;
}

Book& operator -= (Book& b, int price) {
	b.price -= price;
	return b;
}

bool operator == (Book b, int price) {
	if (b.price == price) return true;
	else return false;
}
bool operator == (Book b, string title) {
	if (b.title== title) return true;
	else return false;
}
bool operator == (Book b1, Book b2) {
	if (b1.title == b2.title && b1.price == b2.price && b1.pages==b2.pages) return true;
	else return false;
}
bool operator < (string s, Book b) {
	return s < b.title ? true : false;
}
int main() {
	//1
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
	
	//2
	Book c("명품 C++", 30000, 500), d("고품 C++", 30000, 500);
	if (c == 30000)cout << "정가 30000원" << endl;
	if (c == "명품 C++") cout << "명품 C++책입니다." << endl;
	if (c == d)cout << "두 책이 같은 책입니다." << endl;
	
	//3
	Book book("벼룩시작", 0, 50);
	if (!book) cout << "꽁짜다" << endl;

	//4
	Book e("청춘", 20000, 300);
	string s;
	cout << "책 이름을 입력하세요 >>";
	getline(cin, s);
	if (s < e) {
		cout << e.getTitle() << "이 " << s << "보다 뒤에 있구나 !" << endl;
	}
}