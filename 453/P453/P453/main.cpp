#include <vector>

using namespace std;

class Solution {
public:
	int minMoves(vector<int>& nums) {
		int minn = INT_MAX;
		for (auto num : nums) {
			if (num < minn) {
				minn = num;
			}
		}
		int answer = 0;
		for (auto num : nums) {
			answer += (num - minn);
		}
		return answer;
	}
};