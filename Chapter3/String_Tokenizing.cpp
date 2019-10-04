#include <iostream>
#include <cstring>

using namespace std;

int main() {
	string str_arr[1000];
	int str_cnt = 0;
	string a = "1945/8/15";
	char* str_buff = new char[1000];
	strcpy(str_buff, a.c_str());

	char* tok = strtok(str_buff, "/");
	while (tok != NULL) {
		str_arr[str_cnt++] = string(tok);
		tok = strtok(NULL, "/");
	}

	for (int n = 0; n < str_cnt; n++) {
		cout << str_arr[n] << endl;
	}
}