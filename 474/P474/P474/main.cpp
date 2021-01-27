#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < strs.size(); i++) {
			int num0 = cnt0(strs[i]);
			int num1 = cnt1(strs[i]);
			for (int j = m; j >= num0; j--) {
				for (int k = n; k >= num1; k--) {
					dp[j][k] = max(dp[j][k], dp[j - num0][k - num1] + 1);
				}
			}
		}
		return dp[m][n];
	}

	int cnt0(string& s) {
		int ret = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				ret++;
			}
		}
		return ret;
	}

	int cnt1(string& s) {
		int ret = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				ret++;
			}
		}
		return ret;
	}
};