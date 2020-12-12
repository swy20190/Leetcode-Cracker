#include <vector>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> answer;
		answer.push_back(0);
		for (int i = 1; i <= num; i++) {
			if (i % 2 == 0) {
				answer.push_back(answer[i / 2]);
			}
			else {
				answer.push_back(answer[i / 2] + 1);
			}
		}
		return answer;
	}
};