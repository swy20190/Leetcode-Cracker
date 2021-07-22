#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) {
			return 0;
		}
		int max_index = -1, max_value = INT_MIN;
		int sec_value = INT_MIN;
		for (int i = 0; i < len; i++) {
			if (nums[i] > max_value) {
				max_index = i;
				sec_value = max_value;
				max_value = nums[i];
			}
			else if (nums[i] > sec_value) {
				sec_value = nums[i];
			}
		}
		if (max_value >= sec_value * 2) {
			return max_index;
		}
		else {
			return -1;
		}
	}
};