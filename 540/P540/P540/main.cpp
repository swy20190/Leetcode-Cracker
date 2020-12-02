#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return nums[0];
		}
		return findAnswer(nums, 0, len - 1);
	}

	int findAnswer(vector<int>& nums, int low, int high) {
		while (low < high) {
			int mid = (low + high) / 2;
			if ((mid - low) % 2 == 0) {
				if (nums[mid - 1] == nums[mid]) {
					high = mid;
				}
				else if (nums[mid] == nums[mid + 1]) {
					low = mid;
				}
				else {
					return nums[mid];
				}
			}
			else {
				if (nums[mid - 1] == nums[mid]) {
					low = mid + 1;
				}
				else if (nums[mid] == nums[mid + 1]) {
					high = mid - 1;
				}
				else {
					return nums[mid];
				}
			}
		}
		return nums[low];
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 1, 1, 2, 2, 3 };
	cout << solution.singleNonDuplicate(nums);
}