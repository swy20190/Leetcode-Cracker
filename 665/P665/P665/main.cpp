#include <vector>

using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int cnt = 0;
		int len = nums.size();
		if (len <= 2) {
			return true;
		}
		for (int i = 1; i < len; i++) {
			if (nums[i - 1] > nums[i]) {
				if (i > 1 && nums[i - 2] > nums[i] && i + 1 < len && nums[i - 1] > nums[i + 1]) {
					return false;
				}
				else {
					cnt++;
					if (cnt == 2) {
						return false;
					}
				}
			}
		}
		return true;
	}
};