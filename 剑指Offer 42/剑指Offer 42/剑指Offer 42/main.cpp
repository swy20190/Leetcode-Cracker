#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		int* dp = new int[len];
		dp[0] = nums[0];
		for (int i = 1; i < len; i++) {
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		}
		int answer = INT_MIN;
		for (int i = 0; i < len; i++) {
			if (dp[i] > answer) {
				answer = dp[i];
			}
		}
		return answer;
	}
};