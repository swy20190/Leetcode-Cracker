#include <vector>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int height = board.size();
		int width = board[0].size();
		vector<vector<int>> next_state(height, vector<int>(width));
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int live_cnt = 0;
					if (i - 1 >= 0) {
						if (j - 1 >= 0) {
							if (board[i - 1][j - 1] == 1) {
								live_cnt++;
							}
						}
						if (board[i - 1][j] == 1) {
							live_cnt++;
						}
						if (j + 1 < width) {
							if (board[i - 1][j + 1] == 1) {
								live_cnt++;
							}
						}
					}
					if (j - 1 >= 0) {
						if (board[i][j - 1] == 1) {
							live_cnt++;
						}
					}
					if (j + 1 < width) {
						if (board[i][j + 1] == 1) {
							live_cnt++;
						}
					}
					if (i + 1 < height) {
						if (j - 1 >= 0) {
							if (board[i + 1][j - 1] == 1) {
								live_cnt++;
							}
						}
						if (board[i + 1][j] == 1) {
							live_cnt++;
						}
						if (j + 1 < width) {
							if (board[i + 1][j + 1] == 1) {
								live_cnt++;
							}
						}
					}
				if (live_cnt < 2 && board[i][j]==1) {
					next_state[i][j] = 0;
				}
				else if (live_cnt > 3 && board[i][j] == 1) {
					next_state[i][j] = 0;
				}
				else if (live_cnt == 3 && board[i][j] == 0) {
					next_state[i][j] = 1;
				}
				else if ((live_cnt == 2 || live_cnt == 3) && board[i][j] == 1) {
					next_state[i][j] = 1;
				}
				else {
					next_state[i][j] = 0;
				}
			}
		}
		board = next_state;
	}
};