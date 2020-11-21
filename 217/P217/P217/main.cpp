#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> ss;
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			ss.insert(nums[i]);
		}
		if (ss.size() < len) {
			return true;
		}
		else {
			return false;
		}
	}
};