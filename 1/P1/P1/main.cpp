#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> answer;
		unordered_map<int, int> h_m;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (h_m.count(target - nums[i]) > 0) {
				answer.push_back(i);
				answer.push_back(h_m.at(target - nums[i]));
				break;
			}
			h_m.insert(pair<int, int>(nums[i], i));
		}

		return answer;
	}
};

int main() {
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	int target = 9;
	Solution solution;
	vector<int> ans = solution.twoSum(nums, target);
	cout << ans[0] << " " << ans[1] << endl;
}