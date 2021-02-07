#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int len = nums.size();
		unordered_map<int, int> index_map;
		if (len <= k) {
			for (int i = 0; i < len; i++) {
				index_map[nums[i]]++;
				if (index_map[nums[i]] > 1) {
					return true;
				}
			}
			return false;
		}
		else {
			for (int i = 0; i <= k; i++) {
				index_map[nums[i]]++;
				if (index_map[nums[i]] > 1) {
					return true;
				}
			}
			int left = 0;
			int right = k + 1;
			while (right < len) {
				index_map[nums[left]]--;
				index_map[nums[right]]++;
				if (index_map[nums[right]] > 1) {
					return true;
				}
				left++;
				right++;
			}
			return false;
		}
	}
};