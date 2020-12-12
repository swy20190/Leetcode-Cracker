#include <vector>

using namespace std;

class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int answer = 0;
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return 1;
		}
		long* diff = new long[len - 1];
		for (int i = 0; i < len - 1; i++) {
			diff[i] = nums[i] - nums[i + 1];
		}
		int flag;
		int start = 0;
		while (start < len - 1) {
			if (diff[start] != 0) {
				break;
			}
			start++;
		}
		if (start == len - 1) {
			return 1;
		}
		if (diff[start] > 0) {
			flag = 0;
		}
		else {
			flag = 1;
		}

		int change_cnt = 0;
		for (int i = 0; i < len - 1; i++) {
			if (diff[i] > 0 && flag == 0) {
				change_cnt++;
				flag = 1;
			}
			else if (diff[i] < 0 && flag == 1) {
				change_cnt++;
				flag = 0;
			}
		}
		return change_cnt + 1;
	}
};