#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		int len = nums.size();
		vector<string> answer;
		if (len == 0) {
			return answer;
		}
		int head = 0;
		int tail = 0;
		while (tail < len) {
			if (tail + 1 >= len || nums[tail] + 1 != nums[tail + 1]) {
				if (tail == head) {
					string curr = to_string(nums[head]);
					answer.push_back(curr);
					head++;
					tail++;
				}
				else {
					string curr = to_string(nums[head]) + "->" + to_string(nums[tail]);
					answer.push_back(curr);
					tail++;
					head = tail;
				}
			}
			else {
				tail++;
			}
		}
		return answer;
	}
};