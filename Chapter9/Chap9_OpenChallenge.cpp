#include <iostream>
#include <ctime>
using namespace std;

class GameObject {
protected:
	int distance;
	int x, y;
public:
	GameObject(int startX, int startY, int distance) {
		this->x = startX; this->y = startY; this->distance = distance;
	}
	virtual ~GameObject() {};

	virtual void move() = 0;
	virtual char getShape() = 0;

	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) {
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}
};

class Human : public GameObject {
public:
	Human(int x, int y, int d) : GameObject(x, y, d) {}
	virtual void move() {
		char c;
		cout << "왼쪽(a) 아래(s) 위(d) 오른쪽(f) >>";
		cin >> c;
		int tmp;
		switch (c) {
		case 'a':
			tmp = x - distance;
			if (tmp < 0) { tmp = 20 + tmp; }
			x = tmp;
			cout << x << endl;
			break;
		case 's':
			tmp = y + distance;
			if (tmp > 9) { tmp = tmp - 10; }
			y = tmp;
			break;
		case 'd':
			tmp = y - distance;
			if (tmp < 0) { tmp = 10 + tmp; }
			y = tmp;
			break;
		case 'f':
			tmp = x + distance;
			if (tmp > 19) { tmp = tmp - 20; }
			x = tmp;
			break;
		}
	}
	virtual char getShape() { return 'H'; }
};
class Monster : public GameObject {
public:
	Monster(int x, int y, int d) : GameObject(x, y, d) {}
	virtual void move() {
		int direction = rand() % 4;
		int tmp;
		switch (direction) {
		case 0:
			tmp = x - distance;
			if (tmp < 0) { tmp = 20 + tmp; }
			x = tmp;
			break;
		case 1:
			tmp = y + distance;
			if (tmp > 9) { tmp = tmp - 10; }
			y = tmp;
			break;
		case 2:
			tmp = y - distance;
			if (tmp < 0) { tmp = 10 + tmp; }
			y = tmp;
			break;
		case 3:
			tmp = x + distance;
			if (tmp > 19) { tmp = tmp - 20; }
			x = tmp;
			break;
		}
	}
	virtual char getShape() { return 'M'; }
};
class Food : public GameObject {
public:
	Food(int x, int y, int d) : GameObject(x, y, d) {}
	virtual void move() {
		int isMove = rand() % 5;
		if (isMove <= 1) {
			int direction = rand() % 4;
			int tmp;
			switch (direction) {
			case 0:
				tmp = x - distance;
				if (tmp < 0) { tmp = 20 + tmp; }
				x = tmp;
				break;
			case 1:
				tmp = y + distance;
				if (tmp > 9) { tmp = tmp - 10; }
				y = tmp;
				break;
			case 2:
				tmp = y - distance;
				if (tmp < 0) { tmp = 10 + tmp; }
				y = tmp;
				break;
			case 3:
				tmp = x + distance;
				if (tmp > 19) { tmp = tmp - 20; }
				x = tmp;
				break;
			}
		}
	}
	virtual char getShape() { return '@'; }
};
class Game {
	Human* h;
	Monster* m;
	Food* f;
public:
	Game() {
		h = new Human(0, 0, 1);
		m = new Monster(6, 6, 2);
		f = new Food(12, 9, 1);
	}
	void show() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				if (h->getX() == j && h->getY() == i) { cout << h->getShape(); }
				else if(m->getX() == j && m->getY() == i) { cout << m->getShape(); }
				else if (f->getX() == j && f->getY() == i) { cout << f->getShape(); }
				else { cout << "-"; }
 			}
			cout << endl;
		}

	}
	void play() {
		cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl;
		while (true) {
			show();
			h->move();
			m->move();
			f->move();
			if (h->collide(m)) { cout << "Defeat" << endl; break; }
			if (h->collide(f)) { cout << "Victory" << endl; break; }
		}
	}
};

int main() {
	srand((unsigned)time(0));
	Game gg;
	gg.play();
}