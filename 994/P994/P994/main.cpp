#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int height = grid.size();
		if (height == 0) {
			return 0;
		}
		int width = grid[0].size();
		if (width == 0) {
			return 0;
		}
		queue<vector<int>> oranges;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (grid[i][j] == 2) {
					oranges.push({ i, j });
				}
			}
		}

		int answer = 0;
		while (!oranges.empty()) {
			queue<vector<int>> next_oranges;
			while (!oranges.empty()) {
				vector<int> point = oranges.front();
				int h = point[0];
				int w = point[1];
				if (h - 1 >= 0 && grid[h - 1][w] == 1) {
					grid[h - 1][w] = 2;
					next_oranges.push({ h - 1, w });
				}
				if (h + 1 < height && grid[h + 1][w] == 1) {
					grid[h + 1][w] = 2;
					next_oranges.push({ h + 1, w });
				}
				if (w - 1 >= 0 && grid[h][w - 1] == 1) {
					grid[h][w - 1] = 2;
					next_oranges.push({ h, w - 1 });
				}
				if (w + 1 < width && grid[h][w + 1] == 1) {
					grid[h][w + 1] = 2;
					next_oranges.push({ h, w + 1 });
				}
				oranges.pop();
			}
			oranges = next_oranges;
			if (!oranges.empty()) {
				answer++;
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (grid[i][j] == 1) {
					return -1;
				}
			}
		}

		return answer;
	}
};