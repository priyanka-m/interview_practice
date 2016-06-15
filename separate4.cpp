/**
Given an array of four different types, segregate all 4 types. This is an extension of the even odd problem.

Input: 1, 3, 4, 1, 2, 2, 4, 3, 1
Output: 1, 1, 1, 2, 2, 3, 3, 4, 4
*/

#include <iostream>
#include <vector>

using namespace std;

void dump(vector<int> numbers) {
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
}

bool isMember(int n, vector<int>& group) {
	return (find(group.begin(), group.end(), n) != group.end());
}

void separateTwoUnique(vector<int>& numbers, int beg, int end, vector<int>& group1, vector<int>& group2) {
	for (int i = beg, j = end; i <= j;) {
		if (isMember(numbers[i], group2) && isMember(numbers[j], group1)) {
			swap(numbers[i], numbers[j]);
			i++;
			j--;
		} else {
			if (isMember(numbers[i], group1)) {
				i++;
			}
			if (isMember(numbers[j], group2)) {
				j--;
			}
		}
	}
}

int findPointOfDivision(vector<int>& numbers, vector<int>& group1, vector<int>& group2) {
	for (int i = 0; i < numbers.size() - 2; i++) {
		if (isMember(numbers[i], group1) && isMember(numbers[i + 1], group2)) {
			return i;
		}
	}
	return -1;
}

vector<int> vectorInit(string s) {
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i] - '0');
	}
	return v;
}

/** 
* Treat 1 & 2 as one group and treat 3 & 4 as one group.
* shuffle the numbers such that 1 and 2 are on one side and,
*  and 4 are on the other.
*/
void segregateFourUnique(vector<int>& numbers) {
	vector<int> group1 = vectorInit("1, 2"), group2 = vectorInit("3, 4");

	// Separate the array into 2 groups
	separateTwoUnique(numbers, 0, numbers.size() - 1, group1, group2);
	
	// Find the index that divides the array into 2 groups.
	int point = findPointOfDivision(numbers, group1, group2);

	if (point != -1) {
		// Separate the 2 groups further
		vector<int> g1 = vectorInit("1"), g2 = vectorInit("2"), g3 = vectorInit("3"), g4 = vectorInit("4");
		separateTwoUnique(numbers, 0, point, g1, g2);
		separateTwoUnique(numbers, point + 1, numbers.size() - 1, g3, g4);
	}

}

int main() {
	int arr[] = {2, 3, 4, 1, 2, 2, 4, 3, 1};
	vector<int> varr(arr, arr + sizeof(arr)/sizeof(arr[0]));
	segregateFourUnique(varr);
	dump(varr);
	return 0;
}