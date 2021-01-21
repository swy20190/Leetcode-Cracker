#include <vector>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int height = grid.size();
		if (height == 0) {
			return 0;
		}
		int width = grid[0].size();
		if (width == 0) {
			return 0;
		}
		int answer = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (grid[i][j] == 1) {
					int area = inflection(grid, i, j);
					if (area > answer) {
						answer = area;
					}
				}
			}
		}
		return answer;
	}

	int inflection(vector<vector<int>>& map, int row, int col) {
		if (row < 0 || row >= map.size() || col < 0 || col >= map[0].size()) {
			return 0;
		}
		if (map[row][col] == 0 || map[row][col] == 2) {
			return 0;
		}
		else {
			int ret = 1;
			map[row][col] = 2;
			return ret + inflection(map, row - 1, col) + inflection(map, row + 1, col) + inflection(map, row, col - 1) + inflection(map, row, col + 1);
		}
	}
};