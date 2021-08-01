#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findLHS(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int l = 0;
		int r = 0;
		for (int end = 0; end < nums.size(); end++) {
			while (nums[end] - nums[l] > 1) {
				l++;
			}
			if (nums[end] - nums[l] == 1) {
				r = max(r, end - l + 1);
			}
		}
		return r;
	}
};