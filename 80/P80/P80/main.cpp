#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int curr = 0;
		for (int num : nums) {
			if (curr<2 || num>nums[curr - 2]) {
				nums[curr] = num;
				curr++;
			}
		}
		return curr;
	}
};