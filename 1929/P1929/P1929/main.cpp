#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getConcatenation(vector<int>& nums) {
		vector<int> answer = nums;
		for (auto num : nums) {
			answer.push_back(num);
		}
		return answer;
	}
};