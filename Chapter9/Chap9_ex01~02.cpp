#include <iostream>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다.";
		cout << getSourceString() << "을 입력하세요 >> ";
		cin >> src;
		cout << "변환결과: " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
protected:
	virtual double convert(double src) { return src / this->ratio; }
	virtual string getSourceString() { return "원"; }
	virtual string getDestString() { return "달러"; }

public:
	WonToDollar(double ratio) : Converter(ratio) {}
	//void run() { Converter::run(); } 상속받으므로 굳이 X
};

class KmToMile : public Converter {
protected:
	virtual double convert(double src) { return src / this->ratio; }
	virtual string getSourceString() { return "Km"; }
	virtual string getDestString() { return "Mile"; }

public:
	KmToMile(double ratio) : Converter(ratio) {}
};


int main() {
	//1
	WonToDollar wd(1010);
	wd.run();
	cout << endl;

	//2
	KmToMile toMile(1.609344);
	toMile.run();

}