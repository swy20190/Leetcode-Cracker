#include <vector>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return -1;
		}
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		int front_sum = 0;
		for (int i = 0; i < len; i++) {
			if (2 * front_sum + nums[i] == sum) {
				return i;
			}
			front_sum += nums[i];
		}
		return -1;
	}
};