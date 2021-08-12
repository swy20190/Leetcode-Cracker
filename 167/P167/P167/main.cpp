#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> answer;
		int head = 0;
		int tail = numbers.size() - 1;
		while (head<tail) {
			if (numbers[head] + numbers[tail] == target) {
				answer.push_back(head + 1);
				answer.push_back(tail + 1);
				return answer;
			}
			else if (numbers[head] + numbers[tail] > target) {
				tail--;
			}
			else {
				head++;
			}
		}
		return answer;
	}
};