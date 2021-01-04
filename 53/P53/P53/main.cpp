#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int* dp = new int[len];
		if (len == 0) {
			return 0;
		}
		dp[0] = nums[0];
		for (int i = 1; i < len; i++) {
			dp[i] = max(nums[i], dp[i - 1] + nums[i]);
		}
		int maxSub = INT_MIN;
		for (int i = 0; i < len; i++) {
			if (maxSub < dp[i]) {
				maxSub = dp[i];
			}
		}
		return maxSub;
	}
};