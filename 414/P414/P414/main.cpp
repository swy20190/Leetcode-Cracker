#include <vector>

using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long big_1 = LONG_MIN;
		long big_2 = LONG_MIN;
		long big_3 = LONG_MIN;
		int len = nums.size();
		if (len == 1) {
			return nums[0];
		}
		for (int num : nums) {
			if (num > big_1) {
				big_3 = big_2;
				big_2 = big_1;
				big_1 = num;
			}
			else if (num<big_1 && num>big_2) {
				big_3 = big_2;
				big_2 = num;
			}
			else if (num<big_2 && num>big_3) {
				big_3 = num;
			}
		}
		if (big_3 == LONG_MIN) {
			return big_1;
		}
		else {
			return big_3;
		}
	}
};