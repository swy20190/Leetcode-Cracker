#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int getMaximumGenerated(int n) {
		if (n == 0) {
			return 0;
		}
		vector<int> answer;
		answer.push_back(0);
		answer.push_back(1);
		for (int i = 2; i <= n; i++) {
			if (i % 2 == 0) {
				answer.push_back(answer[i / 2]);
			}
			else {
				answer.push_back(answer[i / 2 + 1] + answer[i / 2]);
			}
		}
		return *max_element(answer.begin(), answer.end());
	}
};