#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int bin(vector<int>& nums, int target, bool lower) {
		int left = 0;
		int right = nums.size() - 1;
		int answer = nums.size();
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] > target || (lower&&nums[mid] >= target)) {
				right = mid - 1;
				answer = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return answer;
	}
public:
	int search(vector<int>& nums, int target) {
		int leftIdx = bin(nums, target, true);
		int rightIdx = bin(nums, target, false) - 1;
		if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
			return rightIdx - leftIdx + 1;
		}
		return 0;
	}
};