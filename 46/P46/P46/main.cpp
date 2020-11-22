#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> answer;
		int* visited = new int[nums.size()];
		for (int i = 0; i < nums.size(); i++) {
			visited[i] = 0;
		}
		vector<int> tmp;
		backtrack(answer, nums, tmp, visited);
		return answer;
	}

	void backtrack(vector<vector<int>>& permuted, vector<int>& nums, vector<int>& tmp, int* visited) {
		if (tmp.size() == nums.size()) {
			permuted.push_back(tmp);
			return;
		}
		else {
			for (int i = 0; i < nums.size(); i++) {
				if (visited[i] == 0) {
					tmp.push_back(nums[i]);
					visited[i] = 1;
					backtrack(permuted, nums, tmp, visited);
					visited[i] = 0;
					tmp.pop_back();
				}
			}
		}
	}
};