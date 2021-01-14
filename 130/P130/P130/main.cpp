#include <vector>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int height = board.size();
		if (height == 0) {
			return;
		}
		int width = board[0].size();
		if (width == 0) {
			return;
		}
		for (int i = 0; i < width; i++) {
			if (board[0][i] == 'O') {
				reflection(board, 0, i);
			}
			if (board[height - 1][i] == 'O') {
				reflection(board, height - 1, i);
			}
		}
		for (int i = 0; i < height; i++) {
			if (board[i][0] == 'O') {
				reflection(board, i, 0);
			}
			if (board[i][width - 1] == 'O') {
				reflection(board, i, width - 1);
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (board[i][j] == '!') {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}

	void reflection(vector<vector<char>>& board, int x, int y) {
		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()||board[x][y] == 'X' || board[x][y] == '!') {
			return;
		}
		board[x][y] = '!';
		reflection(board, x, y - 1);
		reflection(board, x, y + 1);
		reflection(board, x + 1, y);
		reflection(board, x - 1, y);
	}
};