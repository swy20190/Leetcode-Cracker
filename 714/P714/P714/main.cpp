#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int len = prices.size();
		if (len < 2) {
			return 0;
		}
		int *dp_have_stock = new int[len];
		int *dp_no_stock = new int[len];
		dp_have_stock[0] = -1 * prices[0];
		dp_no_stock[0] = 0;
		for (int i = 1; i < len; i++) {
			dp_have_stock[i] = max(dp_have_stock[i - 1], dp_no_stock[i - 1] - prices[i]);
			dp_no_stock[i] = max(dp_have_stock[i - 1] + prices[i] - fee, dp_no_stock[i - 1]);
		}
		return dp_no_stock[len - 1];
	}
};