#include <vector>

using namespace std;

class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int* dp = new int[amount+1];
		dp[0] = 1;
		for (int i = 1; i <= amount; i++) {
			dp[i] = 0;
		}
		for (auto coin : coins) {
			for (int i = 0; i + coin <= amount; i++) {
				dp[i + coin] += dp[i];
			}
		}
		return dp[amount];
	}
};