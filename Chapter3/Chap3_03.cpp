#include <iostream>
using namespace std;

class Account {
	string owner;
	int id, balance;
public:
	Account(string o, int id, int balance);
	void deposit(int money);
	string getOwner();
	int inquiry();
	int withdraw(int money);
};

Account::Account(string o, int id, int balance) {
	this->owner = o;
	this->id = id;
	this->balance = balance;
}
void Account::deposit(int money) {
	this->balance += money;
}
string Account::getOwner() {
	return owner;
}
int Account::inquiry() {
	return this->balance;
}
int Account::withdraw(int money) {
	if (money < this->balance) {
		this->balance -= money;
		return money;
	}
	else {
		cout << "돈부족" << endl;
		return 0;
	}
}
int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}