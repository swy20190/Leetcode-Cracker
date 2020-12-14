#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int minMoves2(vector<int>& nums) {
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		int target = tmp[tmp.size() / 2];
		int answer = 0;
		for (int num : nums) {
			answer += abs(num - target);
		}
		return answer;
	}
};