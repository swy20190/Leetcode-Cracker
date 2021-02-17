#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		if (nums.size() < 4) {
			return false;
		}
		int sum = 0;
		for (auto num : nums) {
			sum += num;
		}
		if (sum % 4 != 0) {
			return false;
		}
		sort(nums.begin(), nums.end());
		vector<int> buckets(4);
		return pack(nums, nums.size() - 1, buckets, sum / 4);
	}
	bool pack(vector<int>& nums, int pos, vector<int>& sums, int avg) {
		if (pos == -1)
			return sums[0] == avg && sums[1] == avg && sums[2] == avg;
		for (int i = 0; i < 4; ++i) {
			if (sums[i] + nums[pos] > avg) continue;
			sums[i] += nums[pos];
			if (pack(nums, pos - 1, sums, avg))
				return true;
			sums[i] -= nums[pos];
		}
		return false;
	}
};