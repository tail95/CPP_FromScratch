#include <iostream>
using namespace std;

class Printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
protected:
	bool print(int pages) {
		if (availableCount < pages) {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
			return false;
		}
		availableCount -= pages;
		cout << "프린트하였습니다." << endl;
		return true;
	}
public:
	Printer(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
	}
	string getModel() { return this->model; }
	string getManufacturer() { return this->manufacturer; }
	int avCount() { return this->availableCount; }
};

class InkJetPrinter : public Printer{
	int ink;
public:
	InkJetPrinter(string model, string manufacturer, int availableCount, int ink) : Printer(model, manufacturer, availableCount) {
		this->ink = ink;
	}
	int availableInk() { return this->ink; }
	bool printInkJet(int pages) {
		if (print(pages)) {
			this->ink -= pages;
			return true;
		}
		else return false;
	}
};

class LaserPrinter : public Printer {
	int toner;
public:
	LaserPrinter(string model, string manufacturer, int availableCount, int toner) : Printer(model, manufacturer, availableCount) {
		this->toner = toner;
	}
	int availableToner() { return this->toner; }
	bool printLaser(int pages) {
		if (print(pages)) {
			this->toner -= pages;
			return true;
		}
		else return false;
		
	}
};

int main() {
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	cout << "잉크젯: Officejet V40, HP, 남은 종이 5장, 남은 잉크 10" << endl;
	cout << "레이저: SCX-6x45, 삼성전자, 남은 종이 3장, 남은 토너 20" << endl;
	InkJetPrinter* ink = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	LaserPrinter* laser = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);
	
	int id, pages;
	do {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>> ";
		cin >> id >> pages;
		if (id == 1) { ink->printInkJet(pages); }
		else if (id == 2) { laser->printLaser(pages); }
		else {
			cout << "잘못된 프린터를 선택 했습니다." << endl;
			continue;
		}
		cout << ink->getModel() << ", " << ink->getManufacturer() << ", 남은 종이" << ink->avCount() << ", 남은 잉크" << ink->availableInk() << endl;
		cout << laser->getModel() << ", " << laser->getManufacturer() << ", 남은 종이" << laser->avCount() << ", 남은 토너" << laser->availableToner() << endl;
		char answer;
		cout << "계속 프린트 하시겠습니까? (y/n) >> ";
		cin >> answer;
		if (answer == 'n' || answer == 'N') break;
	} while (true);
	

}