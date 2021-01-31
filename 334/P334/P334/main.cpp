#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len < 3) {
			return false;
		}
		int num_max = INT_MAX;
		int num_min = INT_MAX;
		for (int i = 0; i < len; i++) {
			if (nums[i] < num_min) {
				num_min = nums[i];
			}
			else if (nums[i] > num_min && nums[i] < num_max) {
				num_max = nums[i];
			}
			else if (nums[i] > num_max) {
				return true;
			}
		}
		return false;
	}
};