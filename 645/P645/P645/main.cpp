#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> answer;
		int len = nums.size();
		int* bucket = new int[len];
		for (int i = 0; i < len; i++) {
			bucket[i] = 0;
		}
		for (int i = 0; i < len; i++) {
			bucket[nums[i] - 1]++;
		}
		int repeat, lose;
		for (int i = 0; i < len; i++) {
			if (bucket[i] == 0) {
				lose = i + 1;
			}
			if (bucket[i] > 1) {
				repeat = i + 1;
			}
		}
		answer.push_back(repeat);
		answer.push_back(lose);
		return answer;
	}
};