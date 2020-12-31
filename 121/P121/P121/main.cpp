#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len == 0 || len == 1) {
			return 0;
		}
		vector<int> curr_min(len);
		vector<int> curr_max_profit(len);
		curr_min[0] = prices[0];
		for (int i = 1; i < len; i++) {
			curr_min[i] = min(curr_min[i - 1], prices[i]);
			curr_max_profit[i] = prices[i] - curr_min[i - 1];
		}
		int max_profit = INT_MIN;
		for (int i = 1; i < len; i++) {
			if (curr_max_profit[i] > max_profit) {
				max_profit = curr_max_profit[i];
			}
		}
		return max(0, max_profit);
	}
};