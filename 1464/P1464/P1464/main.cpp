#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int firstIndex;
		int secondIndex;
		if (nums[0] > nums[1]) {
			firstIndex = 0;
			secondIndex = 1;
		}
		else {
			firstIndex = 1;
			secondIndex = 0;
		}
		for (int i = 2; i < nums.size(); i++) {
			if (nums[i] >= nums[firstIndex]) {
				secondIndex = firstIndex;
				firstIndex = i;
			}
			else if (nums[i] > nums[secondIndex]) {
				secondIndex = i;
			}
		}
		return (nums[firstIndex] - 1)*(nums[secondIndex] - 1);
	}
};