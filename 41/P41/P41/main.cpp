#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] <= 0) {
				nums[i] = INT_MAX;
			}
		}
		for (int i = 0; i < len; i++) {
			int index = abs(nums[i])-1;
			if (index < len) {
				nums[index] = -1 * abs(nums[index]);
			}
		}
		for (int i = 0; i < len; i++) {
			if (nums[i] >= 0) {
				return i + 1;
			}
		}
		return len + 1;
	}
};

int main() {
	vector<int> nums = { 7,8,9,11,12 };
	Solution solution;
	cout << solution.firstMissingPositive(nums);
}