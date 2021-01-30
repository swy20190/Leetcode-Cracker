#include <vector>

using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
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
					answer += 4;
					if (j + 1 < width && grid[i][j + 1] == 1) {
						answer -= 2;
					}
					if (i + 1 < height && grid[i + 1][j] == 1) {
						answer -= 2;
					}
				}
			}
		}
		return answer;
	}
};