#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

float maxProductSubarray(const vector<int>& arr) {
	float prod = 1;
	for (int i = 0; i < arr.size(); i++) {
		prod *= arr[i];
	}

	float maxProd = prod;
	for (int j = 0, k = arr.size() - 1; j < k; ) {
		if (prod/j > prod/k) {
			prod = prod/j;
			j++;
		} else {
			prod = prod/k;
			k--;
		}
		maxProd = prod > maxProd ? prod : maxProd;
	}
	return maxProd;
}

int main() {
	int arr[] = {8, -2, -2, 0, 8, 0, -6, -8, -6, -1};
	vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
	cout << maxProductSubarray(v);
	return 0;
}