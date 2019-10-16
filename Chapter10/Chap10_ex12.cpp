#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

class Word {
	string english;
	string korean;
public:
	void set(string e, string k) { english = e; korean = k; }
	string getEnglish() { return english; }
	string getKorean() { return korean; }
};

class GameManager {
	vector<Word> v;
public:
	void init() {
		srand((unsigned)time(0));
		string E[10] = { "apple", "banana", "mango", "orange", "grape", "baby", "emotion", "painting", "human", "trade"};
		string K[10] = { "사과", "바나나", "망고", "오렌지", "포도", "아기", "감정", "그림", "사람", "거래"};
		Word w[10];
		for (int i = 0; i < 10; i++) { 
			w[i].set(E[i], K[i]); 
			v.push_back(w[i]);
		}
	}
	void input() {
		cout << "영어 단어에 exit을 입력하면 입력 끝" << endl;
		string english, korean;
		while (true) {
			cout << "영어 >> ";  cin >> english;
			if (english == "exit") break;
			cout << "한글 >> "; cin >> korean;
			Word w;
			w.set(english, korean);
			v.push_back(w);
		}
	}
	void play() {
		cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료" << endl;
		while (true) {
			int question = rand() % v.size();
			cout << v[question].getEnglish() << "?" << endl;
			int answer = rand() % 4 + 1;
			string tmp = "";
			for (int i = 1; i <= 4; i++) {
				if (answer == i) {
					cout << "(" << i << ") " << v[question].getKorean() << ' ';
				}
				else {
					while (true) {
						tmp = v[rand() % v.size()].getKorean();
						if (tmp != v[question].getKorean())
							break;
					}
					cout << "(" << i << ") " << tmp << ' ';
				}

			}
			cout << ":>";
			int n;
			cin >> n;
			if (n < 1 || n>4)break;
			if (n == answer) { cout << "Excellent !!" << endl; }
			else { cout << "NO !!" << endl; }
		}
	}
	void test() {
		int menu;
		cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;
		
		while (true) {
			cout << "어휘 삽입: 1, 어휘 테스트: 2, 프로그램 종료: 그외 키 >> ";
			cin >> menu;
			if (menu == 1) { input(); }
			else if (menu == 2) { play(); }
			else break;
		}
		
	}
	void run() {
		init();
		test();
	}
};

int main() {
	GameManager gm;
	gm.run();
}