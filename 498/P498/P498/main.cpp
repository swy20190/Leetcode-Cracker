#include <vector>

using namespace std;


class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> answer;
		int M = matrix.size();
		if (M == 0) {
			return answer;
		}
		int N = matrix[0].size();
		
		if (N == 0) {
			return answer;
		}
		bool up = true;
		int curr_row = 0;
		int curr_col = 0;
		while (true) {
			answer.push_back(matrix[curr_row][curr_col]);
			if (curr_row == M - 1 && curr_col == N - 1) {
				break;
			}
			if (up) {
				if (curr_row == 0) {
					up = false;
					if (curr_col == N - 1) {
						curr_row++;
					}
					else {
						curr_col++;
					}
				}
				else {
					if (curr_col == N - 1) {
						up = false;
						curr_row++;
					}
					else {
						curr_row--;
						curr_col++;
					}
				}
			}
			else {
				if (curr_col == 0) {
					up = true;
					if (curr_row == M - 1) {
						curr_col++;
					}
					else {
						curr_row++;
					}
				}
				else {
					if (curr_row == M - 1) {
						up = true;
						curr_col++;
					}
					else {
						curr_row++;
						curr_col--;
					}
				}
			}
		}
		return answer;
	}
};