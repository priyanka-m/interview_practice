/**
Given an array, separate out the odd and even numbers
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dump(vector<int> numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
}

void separateOddEven(vector<int>& numbers) {
	for (int i = 0, j = numbers.size() - 1; i <= j;) {
		cout << "current numbers " << numbers[i] << " " << numbers[j] << endl;
		if (!(numbers[i] & 1) && (numbers[j] & 1)) {
			swap(numbers[i], numbers[j]);
			i++;
			j--;
			cout << "swapped " << numbers[i] << " " << numbers[j] << endl;
		} else {
			if (numbers[i] & 1) {
				i++;
				cout << "odd " << numbers[i] << " " << numbers[j] << endl;
			}
			if (!(numbers[j] & 1)) {
				j--;
				cout << "even" << numbers[i] << " " << numbers[j] << endl;
			}
		}
	}
}

int main() {
	int arr[9] = {4, 17, 2, 13, 11, 5, 6, 8, 1}; 
	vector<int> numbers(arr, arr + sizeof(arr)/sizeof(arr[0]));
	separateOddEven(numbers);
	dump(numbers);
	return 0;
}