/**
* Given a string of numbers(12..9), add operators in between(+/-), or concatenate numbers together to form bigger numbers.
* The string should evaluate to a given sum.
*/
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

long int evaluate(string s) {
	long int sum = 0;
	unsigned int i, j;
	int multiplier;

	for (i = 1; i < s.size();) {
		for (j = i; j < s.size() && (s[j] != '+' && s[j] != '-'); j++) {}
		multiplier = (s[i - 1] == '-') ? -1 : 1; 
		sum += ((multiplier * (stoi(s.substr(i, j - i), nullptr, 10))));
		i = j + 1;
	}
	return sum;
}

void addOperators(const string& s, string s1, unsigned int index, long int sum) {
	if (index == s.size() && evaluate(s1) == sum) {
		cout << s1 << endl;
	} else if (index < s.size()) {
		addOperators(s, s1 + "-" + s[index], index + 1, sum);
		addOperators(s, s1 + "+" + s[index], index + 1, sum);
		if (index != 0) {

			addOperators(s, s1 + s[index], index + 1, sum);
		}
	}
}

int main() {
	addOperators("123456789", "", 0, 100);
	return 0;
}
