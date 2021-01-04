#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int answer = 0;
		for (auto num : nums) {
			answer = answer ^ num;
		}
		return answer;
	}
};