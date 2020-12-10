#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int range = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i <= range) {
				range = max(range, i + nums[i]);
			}
		}
		return nums.size() - 1 <= range;
	}
};