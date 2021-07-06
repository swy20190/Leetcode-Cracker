#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		int bucket[101] = { 0 };
		int less_bucket[101] = { 0 };
		for (auto num : nums) {
			bucket[num]++;
		}
		for (int i = 1; i <= 100; i++) {
			less_bucket[i] = less_bucket[i - 1] + bucket[i - 1];
		}
		vector<int> answer;
		for (auto num : nums) {
			answer.push_back(less_bucket[num]);
		}
		return answer;
	}
};