#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int answer = INT_MIN;
		for (int i = 0; i < nums.size() / 2; i++) {
			int pair_sum = nums[i] + nums[nums.size() - 1 - i];
			if (pair_sum > answer) {
				answer = pair_sum;
			}
		}
		return answer;
	}
};