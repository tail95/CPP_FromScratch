#include <iostream>
using namespace std;

class CoffeeMachine {
	int coffee, water, sugar;
public:
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill();
};
CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	this->coffee = c;
	this->water = w;
	this->sugar = s;
}
void CoffeeMachine::drinkEspresso() {
	this->coffee--;
	this->water--;
}
void CoffeeMachine::drinkAmericano() {
	this->coffee--;
	this->water -= 2;
}
void CoffeeMachine::drinkSugarCoffee() {
	this->coffee--;
	this->water -= 2;
	this->sugar--;
}
void CoffeeMachine::show() {
	cout << "커피 머신 상태, 커피:" << this->coffee << "\t물:" << this->water << "\t설탕:" << this->sugar << endl;
}
void CoffeeMachine::fill() {
	this->coffee = 10;
	this->water = 10;
	this->sugar = 10;
}
int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}