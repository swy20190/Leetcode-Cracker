#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 1) {
			return nums[0];
		}
		int head = 0;
		int tail = 1;
		int first = nums[0];
		int second = INT_MAX;
		for (int i = 0; i < len - 1; i++) {
			if (nums[head] > nums[tail]) {
				second = nums[tail];
				break;
			}
			head++;
			tail++;
		}
		return min(first, second);
	}
};