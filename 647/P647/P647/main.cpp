#include <string>

using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int len = s.size();
		if (len == 0) {
			return 0;
		}
		if (len == 1) {
			return 1;
		}
		bool** dp = new bool*[len];
		for (int i = 0; i < len; i++) {
			dp[i] = new bool[len];
		}
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				dp[i][j] = false;
			}
		}
		for(int i = 0; i < len; i++) {
			dp[i][i] = true;
		}
		for (int i = 1; i < len; i++) {
			for (int j = 0; j < len - i; j++) {
				if (s[j] == s[j + i]) {
					if (i == 1) {
						dp[j][j + i] = true;
					}
					else if (dp[j + 1][j + i - 1]) {
						dp[j][j + i] = true;
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				if (dp[i][j]) {
					sum++;
				}
			}
		}
		return sum;
	}
};