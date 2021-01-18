#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		int len = s.size();
		if (len == 0) {
			return 0;
		}
		int** dp = new int*[len];
		for (int i = 0; i < len; i++) {
			dp[i] = new int[len];
		}
		for (int i = 0; i < len; i++) {
			dp[i][i] = 1;
		}
		for (int i = 1; i < len; i++) {
			for (int j = 0; j < len - i; j++) {
				if (s[j] == s[i + j]) {
					if (i == 1) {
						dp[j][i + j] = 2;
					}
					else {
						dp[j][i + j] = dp[j + 1][i + j - 1] + 2;
					}
				}
				else {
					dp[j][i + j] = max(dp[j][i + j - 1], dp[j + 1][i + j]);
				}
			}
		}
		return dp[0][len - 1];
	}
};