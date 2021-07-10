#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int numSpecial(vector<vector<int>>& mat) {
		int row = mat.size();
		int col = mat[0].size();
		int answer = 0;
		for (int i = 0; i < row; i++) {
			int row_sum = 0;
			for (int j = 0; j < col; j++) {
				row_sum += mat[i][j];
			}
			if (row_sum == 1) {
				for (int j = 0; j < col; j++) {
					if (mat[i][j] == 1) {
						int col_sum = 0;
						for (int k = 0; k < row; k++) {
							col_sum += mat[k][j];
						}
						if (col_sum == 1) {
							answer++;
						}
					}
				}
			}
		}
		return answer;
	}
};