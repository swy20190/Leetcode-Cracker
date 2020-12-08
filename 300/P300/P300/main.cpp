#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		vector<int> tmp;
		for (auto& num : nums) {
			if (tmp.empty() || tmp[tmp.size() - 1] < num) {
				tmp.push_back(num);
			}
			else {
				int index = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin();
				tmp[index] = num;
			}
		}
		return tmp.size();
	}
};