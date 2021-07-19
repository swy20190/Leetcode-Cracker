#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> runningSum(vector<int>& nums) {
		vector<int> answer(nums.size(), 0);
		answer[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			answer[i] = answer[i - 1] + nums[i];
		}
		return answer;
	}
};