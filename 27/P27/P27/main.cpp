#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int slow = 0;
		int fast = 0;
		while (fast < nums.size()) {
			if (nums[fast] == val) {
				fast++;
			}
			else {
				nums[slow] = nums[fast];
				fast++;
				slow++;
			}
		}
		return slow;
	}
};