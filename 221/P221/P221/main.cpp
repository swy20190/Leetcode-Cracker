#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int height = matrix.size();
		if (height == 0) {
			return 0;
		}
		int width = matrix[0].size();
		if (width == 0) {
			return 0;
		}
		int** dp = new int*[height];
		for (int i = 0; i < height; i++) {
			dp[i] = new int[width];
		}
		for (int i = 0; i < width; i++) {
			if (matrix[0][i] == '1') {
				dp[0][i] = 1;
			}
			else {
				dp[0][i] = 0;
			}
		}
		for (int i = 0; i < height; i++) {
			if (matrix[i][0] == '1') {
				dp[i][0] = 1;
			}
			else {
				dp[i][0] = 0;
			}
		}
		for (int i = 1; i < height; i++) {
			for (int j = 1; j < width; j++) {
				if (matrix[i][j] == '1') {
					dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
				}
				else {
					dp[i][j] = 0;
				}
			}
		}
		int maxSide = INT_MIN;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (dp[i][j] > maxSide) {
					maxSide = dp[i][j];
				}
			}
		}
		return maxSide * maxSide;
	}
};