#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> answer;
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < row; i++) {
			int rec = 0;
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] < matrix[i][rec]) {
					rec = j;
				}
			}
			bool flag = true;
			for (int k = 0; k < matrix.size(); k++) {
				if (matrix[k][rec] > matrix[i][rec]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				answer.push_back(matrix[i][rec]);
			}
		}
		return answer;
	}
};