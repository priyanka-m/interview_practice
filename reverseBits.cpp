#include <iostream>

using namespace std;

uint32_t getBit(uint32_t n, uint i) {
  return (n & (1<<i))>>i;
}

uint32_t setBit(uint32_t n, uint i) {
  return n | (1<<i);
}

uint32_t reverseBits(uint32_t n) {
    uint32_t x = 0;
    for (int i = 0; i < 16; i++) {
        uint32_t low = getBit(n, i);
        uint32_t high = getBit(n, 32-i-1);
        
        if (low) {
            x = setBit(x, 32-i-1);
        }
        if (high) {
            x = setBit(x, i);
        }
    }
    return x;
}

int main() {
	cout << reverseBits(5) << endl;
	cout << reverseBits(4);
	return 0;
}