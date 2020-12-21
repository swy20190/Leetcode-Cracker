#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int len = cost.size();
		if (len == 0 || len == 1) {
			return 0;
		}
		if (len == 2) {
			return min(cost[0], cost[1]);
		}
		int *dp = new int[len];
		dp[0] = 0;
		dp[1] = 0;
		for (int i = 2; i < len; i++) {
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return min(dp[len - 1] + cost[len - 1], dp[len - 2] + cost[len - 2]);
	}
};