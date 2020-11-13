#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	int coinChange(vector<int>& coins, int amount) {
		int* dps = new int[amount+1];
		if (amount == 0) {
			return 0;
		}
		for (int i = 0; i <= amount; i++) {
			dps[i] = 0;
		}

		// int ret = 0;
		int ret = dp_search(dps, coins, amount);
		
		return ret;
	}

	int dp_search(int* dps, vector<int>& coins, int amount) {
		if (amount == 0) {
			return 0;
		}
		if (dps[amount] != 0) {
			return dps[amount];
		}
		int ret = INT_MAX;
		int len = coins.size();
		for (int i = 0; i < len; i++) {
			if (amount - coins[i] >= 0) {
				int tmp = dp_search(dps, coins, amount - coins[i]);
				if (tmp < ret && tmp != -1) {
					ret = tmp;
				}
			}
		}
		if (ret == INT_MAX) {
			dps[amount] = -1;
			return -1;
		}
		dps[amount] = ret + 1;
		return ret+1;
	}
};

int main() {
	Solution solution;
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	int amount = 11;
	cout << solution.coinChange(coins, amount);
}