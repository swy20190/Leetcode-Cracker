#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> answer;
		int row_A = A.size();
		int col_A = A[0].size();
		for (int i = 0; i < col_A; i++) {
			vector<int> new_row;
			for (int j = 0; j < row_A; j++) {
				new_row.push_back(A[j][i]);
			}
			answer.push_back(new_row);
		}
		return answer;
	}
};