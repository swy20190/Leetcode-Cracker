#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		int len = nums.size();
		string answer = std::to_string(nums[0]);
		if (len == 1) {
			return answer;
		}
		if (len == 2) {
			answer = answer + "/";
			answer = answer + std::to_string(nums[1]);
			return answer;
		}
		answer = answer + "/(";
		answer = answer + std::to_string(nums[1]);
		for (int i = 2; i < len; i++) {
			answer = answer + "/";
			answer = answer + std::to_string(nums[i]);
			
		}
		answer = answer + ")";
		return answer;
	}
};