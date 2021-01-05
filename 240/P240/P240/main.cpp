#include <vector>

using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) {
			return false;
		}
		if (matrix[0].empty()) {
			return false;
		}
		return find(matrix, matrix.size() - 1, 0, target);
	}

	bool find(vector<vector<int>>& matrix, int pivot_row, int pivot_col, int target) {
		if (pivot_row < 0 || pivot_col >= matrix[0].size()) {
			return false;
		}
		if (matrix[pivot_row][pivot_col] == target) {
			return true;
		}
		else if (matrix[pivot_row][pivot_col] > target) {
			return find(matrix, pivot_row - 1, pivot_col, target);
		}
		else {
			return find(matrix, pivot_row, pivot_col + 1, target);
		}
	}
};