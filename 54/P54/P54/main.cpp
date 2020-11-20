#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> answer;
		int num_rows = matrix.size();
		if (num_rows == 0) {
			return answer;
		}
		int num_cols = matrix[0].size();
		int round_nums = (min(num_rows, num_cols)+1)/2;
		for (int i = 0; i < round_nums; i++) {
			if (i == (num_rows + 1) / 2 - 1) {
				for (int j = i; j < num_cols - i; j++) {
					answer.push_back(matrix[i][j]);
				}
			}
			else if (i == (num_cols + 1) / 2 - 1) {
				for (int j = i; j < num_rows - i; j++) {
					answer.push_back(matrix[j][i]);
				}
			}
			else {
				for (int j = i; j < num_cols - i; j++) {
					answer.push_back(matrix[i][j]);
				}
				for (int j = i + 1; j < num_rows - i; j++) {
					answer.push_back(matrix[j][num_cols - i - 1]);
				}
				for (int j = num_cols - i - 2; j >= i; j--) {
					answer.push_back(matrix[num_rows - i - 1][j]);
				}
				for (int j = num_rows - i - 2; j > i; j--) {
					answer.push_back(matrix[j][i]);
				}
			}
		}
		return answer;
	}
};

int main() {
	vector<int> row1 = { 1, 2, 3, 4};
	vector<int> row2 = { 5, 6, 7, 8};
	vector<int> row3 = { 9, 10, 11, 12 };
	vector<vector<int>> matrix;
	matrix.push_back(row1);
	matrix.push_back(row2);
	matrix.push_back(row3);
	Solution solution;
	vector<int> answer = solution.spiralOrder(matrix);
	for (int i = 0; i < 12; i++) {
		cout << answer[i] << " ";
	}
}