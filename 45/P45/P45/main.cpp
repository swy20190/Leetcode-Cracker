#include <vector>

using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		if (len == 0 || len == 1) {
			return 0;
		}
		int jmp_cnt = 1;
		int curr_max = nums[0];
		int next_max = 0;
		for (int i = 0; i < len; i++) {
			if (i <= curr_max) {
				if (i + nums[i] > next_max) {
					next_max = i + nums[i];
				}
			}
			else {
				jmp_cnt++;
				curr_max = next_max;
				next_max = i + nums[i];
			}
		}
		return jmp_cnt;
	}
};