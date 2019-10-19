#include <iostream>
#include <vector>
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

protected:
	virtual void draw() = 0;
public:
	Shape() { }
	virtual ~Shape() {}
	void paint() { draw(); }
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
	vector<Shape*> v;
	int count;
public:
	GraphicEditor() {
		cout << "그래픽 에디터 입니다." << endl;
		count = 0;
	}
	void add(Shape* p) { v.push_back(p); }
	void create(int num) {
		if (num == 1) {
			add(new Line());
		}
		else if (num == 2) {
			add(new Circle());
		}

		else if (num == 3) {
			add(new Rect());
		}
	}
	void dele(int num) {
		vector<Shape*>::iterator it;
		it = v.begin();
		for (int i = 0; i < num; i++) {
			it++;
		}
		it = v.erase(it);
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
				for (int i = 0; i < v.size(); i++) {
					cout << i << ": ";
					v[i]->paint();
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