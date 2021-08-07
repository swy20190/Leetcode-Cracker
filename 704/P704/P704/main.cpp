#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		auto it = find(nums.begin(), nums.end(), target);
		if (it != nums.end()) {
			return distance(begin(nums), it);
		}
		return -1;
	}
};