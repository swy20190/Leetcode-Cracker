#include <vector>

using namespace std;

class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int answer = 0;
		for (int num : nums) {
			if ((num >= 10 && num < 100) || (num >= 1000 && num < 10000) || num == 100000) {
				answer++;
			}
		}
		return answer;
	}
};