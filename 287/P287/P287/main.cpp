#include <vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int len = nums.size();
		int ptr = 0;
		while (nums[ptr] != 0) {
			int tmp = nums[ptr];
			nums[ptr] = 0;
			ptr = tmp;
		}
		return ptr;
	}
};