#include <vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int cnt = 0;
		int boss = nums[0];
		for (auto num : nums) {
			if (num == boss) {
				cnt++;
			}
			else {
				if (cnt == 0) {
					boss = num;
				}
				else {
					cnt--;
				}
			}
		}
		return boss;
	}
};