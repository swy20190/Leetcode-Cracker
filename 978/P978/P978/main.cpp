#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxTurbulenceSize(vector<int>& arr) {
		int len = arr.size();
		int** dp = new int*[2];
		for (int i = 0; i < 2; i++) {
			dp[i] = new int[len];
		}
		dp[0][0] = 1;
		dp[1][0] = 1;
		for (int i = 1; i < len; i++) {
			if (arr[i] > arr[i - 1]) {
				dp[1][i] = dp[0][i-1]+1;
				dp[0][i] = 1;
			}
			else if (arr[i] < arr[i - 1]) {
				dp[0][i] = dp[1][i-1]+1;
				dp[1][i] = 1;
			}
			else {
				dp[0][i] = 1;
				dp[1][i] = 1;
			}
		}
		int max_len = -1;
		for (int i = 0; i < len; i++) {
			max_len = max(max_len, max(dp[0][i], dp[1][i]));
		}
		return max_len;
	}
};