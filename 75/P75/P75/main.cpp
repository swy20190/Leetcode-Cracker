#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int ptr0 = 0;
		int ptr1 = 0;
		int ptr2 = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				nums[ptr2++] = 2;
				nums[ptr1++] = 1;
				nums[ptr0++] = 0;
			}
			else if (nums[i] == 1) {
				nums[ptr2++] = 2;
				nums[ptr1++] = 1;
			}
			else {
				nums[ptr2++] = 2;
			}
		}
	}
};