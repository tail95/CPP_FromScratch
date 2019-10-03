#pragma once
#include<math.h>
class Exp {
	int base;
	int ex;
public:
	Exp();
	Exp(int base);
	Exp(int base, int ex);
	int getValue();
	int getBase();
	int getExp();
	bool equals(Exp b);
};

Exp::Exp() {
	this->base = 1;
	this->ex = 1;
}
Exp::Exp(int base) {
	this->base = base;
	this->ex = 1;
}
Exp::Exp(int base, int ex) {
	this->base = base;
	this->ex = ex;
}
int Exp::getValue() {
	return pow(this->base, this->ex);
}
int Exp::getBase() {
	return this->base;
}
int Exp::getExp() {
	return this->ex;
}
bool Exp::equals(Exp b) {
	return this->getValue() == b.getValue() ? true : false;
}