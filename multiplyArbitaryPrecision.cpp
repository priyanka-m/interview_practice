/**
* Multiply arbitary precision numbers
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void findProduct(vector<int>& num1, vector<int>& num2) {
	int carry = 0, store = 0;
	vector<int> product(num1.size() + num2.size(), 0), last_product(num1.size() + num2.size(), 0);
	int l = product.size() - 1;

	// Perform multiplication the ususal way
	for (int i = num1.size() - 1; i >= 0; i--) {
		for (int j = num2.size() - 1; j >= 0; j--) {
			store = (carry + (num1[i] * num2[j])) % 10;
			product[l] = store;
			l--;
			carry = (num1[i] * num2[j]) / 10;
		}

		product[l] = carry;

		// Instead of storing all products, keep adding as you go
		carry = 0;
		for (int j = (last_product.size() - 1) - (num1.size() - 1 - i), k = product.size() - 1; 
			j >= 0, k >= 0; j--,k--) {

			store = (carry + last_product[j] + product[k]) % 10;
			carry = (carry + last_product[j] + product[k]) / 10;
			last_product[j] = store;
		}


		l = product.size() - 1;
		carry = 0;
	}

	for (int j = 0; j < last_product.size(); j++) {
		cout << last_product[j];
	}

}

int main() {
	vector<int> num1 = {1, 9, 3, 7, 0, 7, 7, 2, 1};
	vector<int> num2 = {7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
	//vector<int> num1 = {1, 9, 1};
	//vector<int> num2 = {7, 6, 2, 4};
	findProduct(num1, num2);
	return 0;
}