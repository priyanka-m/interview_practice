#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <math.h>

/**
* For a given permutation, find the next permutation in line. For example given 5357, the next permutation is, 5375.
*/

using namespace std;

void numberToVector(vector<int>& v, int perm) {
	int rem;
	for (;perm > 0; perm = perm / 10) {
		rem = perm % 10;
		v.push_back(rem);
	}
	reverse(v.begin(), v.end());
}

void vectorToNumber(vector<int>& v, int *perm) {
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {
		temp += v[i] * pow(10, (v.size() - i - 1));
	}
	*perm = temp;
}

int findNextLargest(vector<int>& num, int index) {
	int nextLargest = index + 1;
	for (int i = index + 1; i < num.size(); i++) {
		if (num[i] < num[nextLargest] && num[i] > num[index]) {
			nextLargest = i;
		}
	}
	return nextLargest;
}

int nextPermutation(int perm) {
	vector<int> num;
	int i;
	numberToVector(num, perm);
	for (i = num.size() - 2; i >= 0; i--) {
		if (num[i] < num[i + 1]) {
			break;
		}
	}

	// find the next number from i + 1 to n, to replace i.
	swap(num[i], num[findNextLargest(num, i)]);

	// reverse from i + 1 to n
	reverse(num.begin() + i + 1, num.end());

	vectorToNumber(num, &perm);

	return perm;
}

int main() {
	cout << nextPermutation(5357);
	cout << nextPermutation(43572);
	return 0;
}