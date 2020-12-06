#include <vector>

using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> answer(len, 1);
		
		
		int left = 1;
		int right = 1;
		for (int i = 0; i < len; i++) {
			answer[i] *= left;
			left *= nums[i];
			answer[len - 1 - i] *= right;
			right *= nums[len - 1 - i];
		}
		return answer;
	}
};