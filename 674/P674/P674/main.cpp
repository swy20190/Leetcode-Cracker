#include <vector>

using namespace std;

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		int* dp = new int[len];
		for (int i = 0; i < len; i++) {
			dp[i] = 1;
		}
		for (int i = 1; i < len; i++) {
			if (nums[i] > nums[i - 1]) {
				dp[i] = dp[i - 1] + 1;
			}
			else {
				dp[i] = 1;
			}
		}
		int answer = 0;
		for (int i = 0; i < len; i++) {
			if (dp[i] > answer) {
				answer = dp[i];
			}
		}
		return answer;
	}
};