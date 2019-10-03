#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char name[5][100];
	cout << "5명의 이름 입력 ;로구분" << endl;
	for (int i = 0; i < 5; i++) {
		cin.getline(name[i], 100, ';');
	}
	int count = 0;
	int max_index = 0;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << " : " << name[i] << endl; 
		if (strlen(name[i]) > count) {
			max_index = i;
			count = strlen(name[i]);
		}
	}
	cout << "가장 긴 이름은 " << name[max_index];

}