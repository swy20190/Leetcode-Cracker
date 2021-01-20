#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		int* dp = new int[len];
		int* dp_repeat = new int[len];
		dp[0] = 1;
		dp_repeat[0] = 1;
		for (int i = 1; i < len; i++) {
			int max_len = 1;
			dp_repeat[i] = 1;
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					if (dp[j] + 1 > max_len) {
						max_len = dp[j] + 1;
						dp_repeat[i] = dp_repeat[j];
					}
					else if (dp[j] + 1 == max_len) {
						dp_repeat[i] += dp_repeat[j];
					}
				}
			}
			dp[i] = max_len;
		}
		int global_max_len = 0;
		for (int i = 0; i < len; i++) {
			if (dp[i] > global_max_len) {
				global_max_len = dp[i];
			}
		}
		int sum = 0;
		for (int i = 0; i < len; i++) {
			if (dp[i] == global_max_len) {
				sum += dp_repeat[i];
			}
		}
		return sum;
	}
};