#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		vector<vector<int>> answer;
		int height = matrix.size();
		if (height == 0) {
			return answer;
		}
		int width = matrix[0].size();
		if (width == 0) {
			return answer;
		}
		answer = matrix;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (answer[i][j] == 1) {
					answer[i][j] = height + width;
				}
				if (i > 0) {
					answer[i][j] = min(answer[i][j], 1 + answer[i - 1][j]);
				}
				if (j > 0) {
					answer[i][j] = min(answer[i][j], 1 + answer[i][j - 1]);
				}
			}
		}
		for (int i = height - 1; i >= 0; i--) {
			for (int j = width - 1; j >= 0; j--) {
				if (i < height - 1) {
					answer[i][j] = min(answer[i][j], 1 + answer[i + 1][j]);
				}
				if (j < width - 1) {
					answer[i][j] = min(answer[i][j], 1 + answer[i][j + 1]);
				}
			}
		}
		return answer;
	}
};