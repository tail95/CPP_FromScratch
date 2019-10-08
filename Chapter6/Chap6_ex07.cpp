#include <iostream>
#include <ctime>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = 32767) { return rand() % (max - min + 1) + min; }
	static char nextAlphabet() {
		bool isupper = false;
		isupper = rand() % 2;
		if (isupper) { return (char)(rand() % 26 + 65); }
		else { return (char)(rand() % 26 + 97); }
	}
	static double nextDouble() { return (double) rand() / 32767; }
};
int main() {
	Random::seed();
	cout << "1~100 랜덤 정수 10개" << endl;
	for (int i = 0; i < 10; i++) { cout << Random::nextInt(1, 100) << ' '; }
	cout << endl << "알파벳 랜덤 10개" << endl;
	for (int i = 0; i < 10; i++) { cout << Random::nextAlphabet() << ' '; }
	cout << endl << "랜덤 실수 10개" << endl;
	for (int i = 0; i < 10; i++) { cout << Random::nextDouble() << ' '; }
}