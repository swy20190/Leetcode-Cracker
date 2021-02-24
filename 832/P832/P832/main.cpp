#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int rows = A.size();
		if (rows == 0) {
			return A;
		}
		int cols = A[0].size();
		if (cols == 0) {
			return A;
		}
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols / 2; j++) {
				int tmp = A[i][j];
				A[i][j] = 1 - A[i][cols - j - 1];
				A[i][cols - 1 - j] = 1 - tmp;
			}
			if (cols % 2 != 0) {
				A[i][cols / 2] = 1 - A[i][cols / 2];
			}
		}
		return A;
	}
};