#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		int len = nums.size();
		if (len < 3) {
			return 0;
		}
		sort(nums.begin(), nums.end());
		int answer = 0;
		for (int i = 0; i < len - 2; i++) {
			for (int j = i + 1; j < len - 1; j++) {
				for (int k = j + 1; k < len; k++) {
					if (nums[i] + nums[j] > nums[k]) {
						answer++;
					}
					else {
						break;
					}
				}
			}
		}
		return answer;
	}
};