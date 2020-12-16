#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return nums[0];
		}
		int* rob_first = new int[len + 1];
		int* no_first = new int[len + 1];
		for (int i = 0; i < len + 1; i++) {
			rob_first[i] = 0;
			no_first[i] = 0;
		}
		rob_first[1] = nums[0];
		no_first[1] = 0;
		for (int i = 2; i < len; i++) {
			rob_first[i] = max(rob_first[i - 1], rob_first[i - 2] + nums[i - 1]);
		}
		for (int i = 2; i <= len; i++) {
			no_first[i] = max(no_first[i - 1], no_first[i - 2] + nums[i - 1]);
		}
		return max(rob_first[len - 1], no_first[len]);
	}
};