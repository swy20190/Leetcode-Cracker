#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> res;
		if (matrix.empty()) return res;
		m = matrix.size();
		n = matrix[0].size();
		vector<vector<bool>> Pacificmark(m, vector<bool>(n, false));
		vector<vector<bool>> Atlanticmark(m, vector<bool>(n, false));

		for (int i = 0; i < m; i++) {
			dfs(matrix, Pacificmark, i, 0);
			dfs(matrix, Atlanticmark, i, n - 1);
		}

		for (int i = 0; i < n; i++) {
			dfs(matrix, Pacificmark, 0, i);
			dfs(matrix, Atlanticmark, m - 1, i);
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (Atlanticmark[i][j] && Pacificmark[i][j]) {
					res.push_back({ i,j });
				}
			}
		}
		return res;
	}
private:
	int m, n;
	int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
	void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& marked, int startx, int starty) {
		marked[startx][starty] = true;

		for (int i = 0; i < 4; i++) {
			int nextx = startx + d[i][0];
			int nexty = starty + d[i][1];
			if (inArea(nextx, nexty) && !marked[nextx][nexty]) {
				if (matrix[nextx][nexty] >= matrix[startx][starty]) {
					dfs(matrix, marked, nextx, nexty);
				}
			}
		}
	}

	bool inArea(const int& x, const int& y) {
		return x >= 0 && x < m && y >= 0 && y < n;
	}
};