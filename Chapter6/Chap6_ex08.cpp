#include <iostream>
using namespace std;

class Trace {
	static string* tag;
	static string* info;
	static int count;
public:
	static void put(string function, string log) {
		tag[count] = function;
		info[count] = log;
		count++;
	}
	static void print() {
		cout << "*****모든 Trace 정보를 출력합니다.*****" << endl;
		for (int i = 0; i < count; i++) {
			cout << tag[i] + ": " + info[i] << endl;
		}
	}
	static void print(string function) {
		cout << function << "*****태그의 Trace 정보를 출력합니다.*****" << endl;
		for (int i = 0; i < count; i++) {
			if (tag[i] == function) {
				cout << function + ": " + info[i] << endl;
			}
			else continue;
		}
	}
};

// 공통으로 사용 하는 static 변수 초기화
int Trace::count = 0;
string* Trace::tag = new string[100];
string* Trace::info = new string[100];

void f() {
	int a, b, c;
	cout << "두개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

int main() {
	Trace::put("main()", "프로그램을 시작합니다.");
	f();
	Trace::put("main()", "종료");

	Trace::print("f()");
	Trace::print();
}