#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int len = nums.size();
		int answer = 0;
		for (int i = 0; i < len; i++) {
			answer += i;
			answer -= nums[i];
		}
		answer += len;
		return answer;
	}
};