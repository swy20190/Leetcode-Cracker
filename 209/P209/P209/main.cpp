#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		int answer = INT_MAX;
		bool find = false;
		int left = 0;
		int right = 0;
		int curr_sum = 0;
		while (right < len) {
			curr_sum += nums[right];
			right++;
			if (curr_sum >= s) {
				find = true;
				while (curr_sum >= s) {
					curr_sum -= nums[left];
					left++;
				}
				answer = min(answer, right - left + 1);
			}
		}
		if (find) {
			return answer;
		}
		else {
			return 0;
		}
	}
};