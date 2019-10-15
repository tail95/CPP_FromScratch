#include <iostream>
using namespace std;

class UI {
public:
	static int menu() {
		int n;
		cout << "삽입: 1, 삭제: 2, 모두보기: 3, 종료: 4 >> ";
		cin >> n;
		return n;
	}
	static int type() {
		int n;
		cout << "선: 1, 원: 2, 사각형: 3 >> ";
		cin >> n;
		return n;
	}
	static int del() {
		int n;
		cout << "삭제하고자 하는 도형의 인덱스>> ";
		cin >> n;
		return n;
	}
};
class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint() { draw(); }
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	Shape* getNext() { return next; }
	void setNext(Shape* p) { this->next = p->next; }
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "LINE" << endl;
	}
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "CIRCLE" << endl;
	}
};

class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "RECT" << endl;
	}
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
	int count;
public:
	GraphicEditor() { 
		cout << "그래픽 에디터 입니다." << endl;
		pStart = NULL;
		pLast = NULL;
		count = 0;
	}
	void create(int num) {
		if (num == 1) {
			if (count == 0) {
				pStart = new Line();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Line());
			count++;
		}
		else if (num == 2) {
			if (count == 0) {
				pStart = new Circle();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Circle());
			count++;
		}

		else if (num == 3) {
			if (count == 0) {
				pStart = new Rect();
				pLast = pStart;
			}
			else
				pLast = pLast->add(new Rect());
			count++;
		}
	}
	void dele(int num) {
		Shape* p = pStart;
		Shape* del = pStart;
		if (num < count) {
			for (int i = 0; i < num; i++) {
				p = del;
				del = del->getNext();
			}
			if (num == 0) {
				pStart = p->getNext();
			}
			else {
				p->setNext(del);
			}
			count--;
			if (count == 1)pLast = pStart;
			delete del;
		}
		else {
			cout << "잘못된 인덱스 선택!" << endl;
		}
	}

	void run() {
		bool flag = true;
		while (flag) {
			switch (UI::menu()) {
			case 1: 
				create(UI::type());
				break;
			case 2:
				dele(UI::del());
				break;
			case 3: {
				Shape* p = pStart;
				for (int i = 0; i < count; i++) {
					cout << i << ": ";
					p->paint();
					p = p->getNext();
				}
				break;
			}
			case 4:
				flag = false;
				break;
			default:
				cout << "잘못된  선택입니다.";
				break;
			}
		}
		
	}
};


int main() {
	GraphicEditor* ge = new GraphicEditor;
	ge->run();
	delete ge;

}