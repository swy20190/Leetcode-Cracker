#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int front_sum = 0;
		unordered_map<int, vector<int>> hash;
		hash[0].push_back(-1);
		int len = nums.size();
		if (len == 0) {
			return 0;
		}
		for (int i = 0; i < len; i++) {
			if (nums[i] == 0) {
				front_sum--;
			}
			else {
				front_sum++;
			}
			hash[front_sum].push_back(i);
			
		}
		int answer = 0;
		for (auto p : hash) {
			int index_max = INT_MIN;
			int index_min = INT_MAX;
			for (auto index : p.second) {
				index_max = max(index_max, index);
				index_min = min(index_min, index);
			}
			int curr_len = index_max - index_min;
			answer = max(answer, curr_len);
		}
		return answer;
	}
};