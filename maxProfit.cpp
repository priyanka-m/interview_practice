/**
Implement the max profit problem, with buy-sell stock twice.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
	
	// Find the maximum profit, you can make from 0 to i and store it.
	vector<int> profits;
	int min = 0, maxProfit = 0, maxIndex = prices.size() - 1;
	for (int i = 0; i < prices.size(); i++) {
		maxProfit = max(maxProfit, prices[i] - prices[min]);
		profits.push_back(maxProfit);
		if (prices[i] < prices[min]) {
			min = i;
		}
	}

	// Maximum profit you can make from ith day to nth day.
	vector<int> profits_backwards;
	maxProfit = 0;
	for (int i = prices.size() - 1; i >= 0; i--) {
		maxProfit = max(maxProfit, prices[maxIndex] - prices[i]);
		profits_backwards.push_back(maxProfit);
		if (prices[i] > prices[maxIndex]) {
			maxIndex = i;
		}
	}

	reverse(profits_backwards.begin(), profits_backwards.end());	

	/** combine profits from 0 to ith day and ith day to nth day
	* to find the maximum
	*/
	for (int i = 0; i < profits.size(); i++) {
		profits[i] = profits[i] + profits_backwards[i];
	}

	return *max_element(begin(profits), end(profits));
}

int main() {
	vector<int> prices = {12, 11, 13, 9, 12, 8, 14, 13, 15};
	cout << maxProfit(prices);
	return 0;
}