#include <vector>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int answer = 0;
		if (grid.size() == 0) {
			return 0;
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1') {
					propagate(grid, i, j);
					answer++;
				}
			}
		}
		return answer;
	}

	void propagate(vector<vector<char>> &map, int x, int y) {
		if (x < 0 || x >= map.size() || y < 0 || y >= map[0].size() || map[x][y] != '1') {
			return;
		}
		map[x][y] = '2';
		propagate(map, x - 1, y);
		propagate(map, x, y - 1);
		propagate(map, x + 1, y);
		propagate(map, x, y + 1);
	}
};