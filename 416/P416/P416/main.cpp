#include <vector>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int e : nums) sum += e;
		if (sum & 1) return false;
		vector<vector<bool>> d(nums.size(), vector<bool>((sum >>= 1) + 1, false));
		for (int i = 0; i < nums.size(); i++) {
			for (int s = 0; s <= sum; s++) {
				if (!i) d[i][s] = (nums[i] == s);
				else d[i][s] = d[i - 1][s] || (s - nums[i] >= 0 ? d[i - 1][s - nums[i]] : false);
			}
		}
		return d[nums.size() - 1][sum];
	}
};