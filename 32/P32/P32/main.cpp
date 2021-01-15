#include <string>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		if (len == 0) {
			return 0;
		}
		int* dp = new int[len];
		dp[0] = 0;
		for (int i = 1; i < len; i++) {
			if (s[i] == '(') {
				dp[i] = 0;
			}
			else {
				int left_index = i - dp[i-1] - 1;
				if (left_index < 0) {
					dp[i] = 0;
				}
				else {
					if (s[left_index] == '(') {
						dp[i] = dp[i - 1] + 2;
						if (left_index > 0) {
							dp[i] = dp[i] + dp[left_index - 1];
						}
					}
					else {
						dp[i] = 0;
					}
				}
			}
		}
		int answer = 0;
		for (int i = 0; i < len; i++) {
			if (dp[i] > answer) {
				answer = dp[i];
			}
		}
		return answer;
	}
};