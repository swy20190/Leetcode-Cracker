#include <vector>

using namespace std;

class Solution {
	auto next(int cur, vector<int>& nums, int n) {
		return ((cur + nums[cur]) % n + n) % n;
	}
public:
	bool circularArrayLoop(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (!nums[i]) {
				continue;
			}
			int slow = i;
			int fast = next(i, nums, n);
			while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast, nums, n)] > 0) {
				if (slow == fast) {
					if (slow != next(slow, nums, n)) {
						return true;
					}
					else {
						break;
					}
				}
				slow = next(slow, nums, n);
				fast = next(next(fast, nums, n), nums, n);
			}
			int add = i;
			while (nums[add] * nums[next(add, nums, n)] > 0) {
				int tmp = add;
				add = next(add, nums, n);
				nums[tmp] = 0;
			}
		}
		return false;
	}
};