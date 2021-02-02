#include <vector>

using namespace std;

class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		int len = nums.size();
		vector<int> digit_one(31);
		for (int num : nums) {
			for (int i = 0; i < 31; i++) {
				int mask = 1 << i;
				if ((mask&num) != 0) {
					digit_one[i]++;
				}
			}
		}
		int answer = 0;
		for (int one : digit_one) {
			answer += one * (len - one);
		}
		return answer;
	}
};