#include <vector>

using namespace std;


class Solution {

	vector<int> nnums;
public:
	Solution(vector<int>& nums) {
		nnums = nums;
	}

	int pick(int target) {
		int len = nnums.size();
		int cnt = 0;
		int index = 0;
		for (int i = 0; i < len; i++) {
			if (nnums[i] == target) {
				cnt++;
				if (rand() % cnt == 0) {
					index = i;
				}
			}
		}
		return index;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */