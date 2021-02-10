#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int** dp = new int*[len];
		for (int i = 0; i < len; i++) {
			dp[i] = new int[2];
		}
		dp[0][0] = 1;
		dp[0][1] = -1;
		for (int i = 1; i < len; i++) {
			int max_len = 0;
			int max_index = -1;
			for (int j = 0; j < i; j++) {
				if (nums[i] % nums[j] == 0) {
					if (dp[j][0] + 1 > max_len) {
						max_len = dp[j][0] + 1;
						max_index = j;
					}
				}
			}
			if (max_len > 1) {
				dp[i][0] = max_len;
				dp[i][1] = max_index;
			}
			else {
				dp[i][0] = 1;
				dp[i][1] = -1;
			}
		}
		int max_end = 0;
		int max_size = 0;
		for (int i = 0; i < len; i++) {
			if (dp[i][0] > max_size) {
				max_size = dp[i][0];
				max_end = i;
			}
		}
		vector<int> answer;
		while (true) {
			answer.push_back(nums[max_end]);
			if (dp[max_end][1] == -1) {
				break;
			}
			max_end = dp[max_end][1];
		}
		return answer;
	}
};