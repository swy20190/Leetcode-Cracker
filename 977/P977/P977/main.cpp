#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		vector<int> answer;
		int len = nums.size();
		if (len == 0) {
			return answer;
		}
		int head = 0;
		int tail = len - 1;
		while (head < tail) {
			if (abs(nums[head]) >= abs(nums[tail])) {
				answer.push_back(nums[head] * nums[head]);
				head++;
			}
			else {
				answer.push_back(nums[tail] * nums[tail]);
				tail--;
			}
		}
		answer.push_back(nums[head] * nums[head]);
		reverse(answer.begin(), answer.end());
		return answer;
	}
};