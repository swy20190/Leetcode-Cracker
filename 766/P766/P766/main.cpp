#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 1; i < col; i++) {
			for (int j = 1; j < row; j++) {
				if (matrix[j][i] != matrix[j - 1][i - 1]) {
					return false;
				}
			}
		}
		return true;
	}
};