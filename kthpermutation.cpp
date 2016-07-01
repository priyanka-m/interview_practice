#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fact(int n) {
	if (n <= 1 ) {
		return 1;
	}
	return n * fact(n - 1);
}

void printVector(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << endl;
}

void kthPermutation(vector<int> v, int k) {
	int i = 0, nextBig = i + 1;
	for (;k > 1;) {
		if (k < fact(v.size() - i - 1)) {
			i++;
			cout << "i = "<<i<<endl;
			printVector(v);
		} else if (k > fact(v.size() - i - 1)) {
			k -= fact(v.size() - i - 1);
			swap(v[i], v[nextBig]);
		} else {
			reverse(v.begin() + i + 1, v.end());
			k -= fact(v.size() - i - 1);
		}
		nextBig += 1;
	}
	printVector(v);
}

int main() {
	vector<int> v = {3, 4, 5, 7};
	// kthPermutation(v, 4);
	// kthPermutation(v, 8);
	// kthPermutation(v, 6);
	kthPermutation(v, 15);
	return 0;
}