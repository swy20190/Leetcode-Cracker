#include <iostream>
#include <vector>


using namespace std;

class Solution {

	int sear(vector<int>& nums, int target, int begin, int end) {
		if (nums.size() == 0) {
			return 0;
		}
		if (end - begin == 1) {
			if (nums[begin] == target) {
				return begin;
			}
			if (nums[begin] > target) {
				return begin;
			}
			else {
				return begin + 1;
			}
		}
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			return mid;
		}
		else if (target < nums[mid]) {
			return sear(nums, target, begin, mid);
		}
		else {
			return sear(nums, target, mid, end);
		}
	}
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return 0;
		}
		return sear(nums, target, 0, nums.size());
	}
};