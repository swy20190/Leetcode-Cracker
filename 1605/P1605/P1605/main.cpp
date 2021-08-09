#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		vector<vector<int>> answer(rowSum.size(), vector<int>(colSum.size(), 0));
		int row_num = rowSum.size();
		int col_num = colSum.size();
		for (int i = 0; i < row_num; i++) {
			for (int j = 0; j < col_num; j++) {
				if (rowSum[i] > colSum[j]) {
					answer[i][j] = colSum[j];
					rowSum[i] -= colSum[j];
					colSum[j] = 0;
				}
				else {
					answer[i][j] = rowSum[i];
					colSum[j] -= rowSum[i];
					rowSum[i] = 0;
				}
			}
		}
		return answer;
	}
};