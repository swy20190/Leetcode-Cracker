#include <vector>

using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> answer;
		for (int i = left; i <= right; i++) {
			int curr = i;
			while (curr) {
				int digit = curr % 10;
				if (digit == 0 || i % digit != 0) {
					break;
				}
				else {
					curr = curr / 10;
				}
			}
			if (curr == 0) {
				answer.push_back(i);
			}
		}
		return answer;
	}
};