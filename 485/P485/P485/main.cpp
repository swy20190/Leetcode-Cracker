#include <vector>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		int max_length = 0;
		int tmp_length = 0;
		for (int i = 0; i < len; i++) {
			if (nums[i] == 1) {
				tmp_length++;
			}
			else {
				if (tmp_length > max_length) {
					max_length = tmp_length;
				}
				tmp_length = 0;
			}
		}
		if (tmp_length > max_length) {
			max_length = tmp_length;
		}
		return max_length;
	}
};