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

	vector<int> output;

	int i;

	while (v.size() > 0) {
		// Find the index from which the resulting permutation will start.
		// For example, if we want to find the 15th permutation for v = {1,2,3,4}
		// i = (15 / )
		i = (k / fact(v.size() - 1));
		
		// Find which permutation starting with the ith index is needed
		k = (k % fact(v.size() - 1));

		output.push_back(v[i]);

		// Remove that element from the remaining array
		v.erase(v.begin() + i);
		
	}
	
	printVector(output);
}

int main() {
	vector<int> v = {3, 4, 5, 7};
	kthPermutation(v, 4);
	kthPermutation(v, 8);
	kthPermutation(v, 6);
	kthPermutation(v, 15);
	return 0;
}