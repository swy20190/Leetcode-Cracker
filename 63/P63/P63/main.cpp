#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[m - 1][n - 1] == 1) {
			return 0;
		}
		int **record = new int*[m];
		for (int i = 0; i < m; i++) {
			record[i] = new int[n];
		}
		int tmp_i = 0;
		for (; tmp_i < n; tmp_i++) {
			if (obstacleGrid[0][tmp_i] == 1) {
				break;
			}
			record[0][tmp_i] = 1;
		}
		for (; tmp_i < n; tmp_i++) {
			record[0][tmp_i] = 0;
		}
		int tmp_j = 0;
		for (; tmp_j < m; tmp_j++) {
			if (obstacleGrid[tmp_j][0] == 1) {
				break;
			}
			record[tmp_j][0] = 1;
		}
		for (; tmp_j < m; tmp_j++) {
			record[tmp_j][0] = 0;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					record[i][j] = 0;
				}
				else {
					record[i][j] = record[i - 1][j] + record[i][j - 1];
				}
			}
		}
		return record[m - 1][n - 1];
	}
};