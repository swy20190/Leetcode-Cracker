#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int len = nums.size();
		if (len == 1) {
			return 0;
		}
		if (nums[0] > nums[1]) {
			return 0;
		}
		if (nums[len - 1] > nums[len - 2]) {
			return len - 1;
		}
		return binSearch(nums, 0, len);
	}

	int binSearch(vector<int>& nums, int start, int end) {
		if (start == end) {
			return -1;
		}
		if (start + 1 == end) {
			return -1;
		}
		int mid = (start + end) / 2;
		if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
			return mid;
		}
		else {
			int left_peak = binSearch(nums, start, mid);
			if (left_peak != -1) {
				return left_peak;
			}
			int right_peak = binSearch(nums, mid, end);
			if (right_peak != -1) {
				return right_peak;
			}
		}
		return -1;
	}
};