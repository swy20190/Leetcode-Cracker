#include <vector>
#include <math.h>

using namespace std;


class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int len = nums.size();
		vector<int> answer;
		if (len == 0) {
			return answer;
		}
		for (int i = 0; i < len; i++) {
			if (nums[abs(nums[i]) - 1] > 0) {
				nums[abs(nums[i]) - 1] *= (-1);
			}
			else {
				answer.push_back(abs(nums[i]));
			}
		}


		return answer;
	}
};