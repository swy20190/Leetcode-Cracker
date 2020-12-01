#include <vector>

using namespace std;


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> answer;
		answer.push_back(-1);
		answer.push_back(-1);
		int len = nums.size();
		if (len == 0) {
			return answer;
		}
		answer[0] = findLeft(nums, 0, len - 1, target);
		answer[1] = findRight(nums, 0, len - 1, target);
		return answer;

	}

	

	int findLeft(vector<int>& nums, int low, int high, int target) {
		int mid = (low + high) / 2;
		while (low <= high) {
			if (nums[mid] == target && (mid == 0 || nums[mid - 1] < target)) {
				return mid;
			}
			else if (nums[mid] < target) {
				low = mid+1;
			}
			else {
				high = mid-1;
			}
			mid = (low + high) / 2;
		}
		return -1;
	}

	int findRight(vector<int>& nums, int low, int high, int target) {
		int mid = (low + high) / 2;
		int len = nums.size();
		while (low <= high) {
			if (nums[mid] == target && (mid == len - 1 || nums[mid + 1] > target)) {
				return mid;
			}
			else if (nums[mid] > target) {
				high = mid-1;
			}
			else {
				low = mid+1;
			}
			mid = (high + low) / 2;
		}
		return -1;
	}
};