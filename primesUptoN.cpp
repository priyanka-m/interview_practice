// Write all primes upto N.
#include <iostream>
#include <vector>
using namespace std;

void printAllPrimes(const long unsigned int n) {
	vector<bool> allNums(n, false);

	for (int i = 2; i < n; i++) {
		for (int j = 2; j < n; j++) {
			if (j % i == 0 && j != i) {
				allNums[j] = true;
			}
		}
	}
	for (int j = 1; j < n; j++) {
		if (!allNums[j]) {
			cout << j << " is prime" << endl;
		}
	}
}

int main() {
	printAllPrimes(14);
	return 0;
}