#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numSubarraysWithSum(vector<int>& nums, int goal) {
		unordered_map<int, int> preSum;
		int answer = 0;
		int sum = 0;
		for (auto num : nums) {
			preSum[sum]++;
			sum += num;
			answer += preSum[sum - goal];
		}
		return answer;
	}
};