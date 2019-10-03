#include <iostream>
#include "Chap3_OC.h"

using namespace std;

int main()
{
	Exp a(3, 2);
	Exp b(9);
	Exp c;

	cout << a.getValue() << ' ' << b.getValue() << ' ' << c.getValue() << endl;
	cout << "a의 베이스 " << a.getBase() << ',' << "지수 " << a.getExp() << endl;

	if (a.equals(b)) cout << "SAME" << endl;
	else cout << "DIFFERENT" << endl;
}

