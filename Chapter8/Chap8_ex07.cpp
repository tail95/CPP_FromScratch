#include <iostream>
using namespace std;

class BaseMemory {
	char* mem;
	int size;
protected:
	BaseMemory(int size) { mem = new char[size]; this->size = size; }
	void load(char* mem, int address, int size) {
		if (address + size > this->size) return;
		for (int i = 0; i < size; i++) {
			this->mem[address + i] = mem[i];
		}
	}
public:
	char read(int address) { return this->mem[address]; } // ROM과 RAM모두 사용
};

class ROM : public BaseMemory {
public:
	ROM(int capacity, char* x, int size) : BaseMemory(capacity) { load(x, 0, size); }
};

class RAM : public BaseMemory {
public:
	RAM(int capacity) : BaseMemory(capacity) {}
	void write(int address, char item) { load(&item, address, 1); }
};

int main() {
	char x[5] = { 'h', 'e','l','l','o' };
	ROM biosROM(1024 * 10, x, 5);
	RAM mainMemory(1024 * 1024);
	
	for (int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
}