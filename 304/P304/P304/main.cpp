#include <vector>

using namespace std;

class NumMatrix {
	vector<vector<int>> front_sum;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		int height = matrix.size();
		if (height == 0) {
			return;
		}
		int width = matrix[0].size();
		if (width == 0) {
			return;
		}
		vector<int> first_row(width + 1);
		front_sum.push_back(first_row);
		int curr_sum = 0;
		for (int i = 0; i < height; i++) {
			curr_sum = 0;
			vector<int> tmp_row;
			tmp_row.push_back(0);
			for (int j = 0; j < width; j++) {
				curr_sum += matrix[i][j];
				tmp_row.push_back(curr_sum + front_sum[i][j+1]);
			}
			front_sum.push_back(tmp_row);
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return front_sum[row2 + 1][col2 + 1] - front_sum[row1][col2 + 1] - front_sum[row2 + 1][col1] + front_sum[row1][col1];
	}
};