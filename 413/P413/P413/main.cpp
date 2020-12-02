#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int len = A.size();
		if (len < 3) {
			return 0;
		}
		vector<int> dp(len, 0);
		for (int i = 2; i < len; i++) {
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
				dp[i] = dp[i - 1] + 1;
			}
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};