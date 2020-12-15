#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		int slow = 0;
		int fast = 0;
		while (fast < nums.size()) {
			while (fast<nums.size() && nums[slow] == nums[fast]) {
				fast++;
			}
			if (fast == nums.size()) {
				break;
			}
			slow++;
			nums[slow] = nums[fast];
		}
		return slow + 1;
	}
};