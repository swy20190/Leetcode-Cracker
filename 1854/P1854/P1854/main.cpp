#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maximumPopulation(vector<vector<int>>& logs) {
		int nums[150] = { 0 };
		int answer = 0;
		int c = 0;
		for (int i = 0; i < logs.size(); i++) {
			nums[logs[i][0] - 1949]++;
			nums[logs[i][1] - 1949]--;
		}
		for (int i = 1; i < 150; i++) {
			nums[i] += nums[i - 1];
			if (nums[i] > c) {
				c = nums[i];
				answer = i + 1949;
			}
		}
		return answer;
	}
};