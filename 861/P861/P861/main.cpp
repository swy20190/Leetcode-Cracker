#include <vector>

using namespace std;


class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); i++) {
			if (A[i][0] == 0) {
				row_reverse(A, i);
			}
		}

		for (int i = 1; i < A[0].size(); i++) {
			int cnt = 0;
			for (int j = 0; j < A.size(); j++) {
				if (A[j][i] == 0) {
					cnt++;
				}
			}
			if (cnt > A.size() - cnt) {
				col_reverse(A, i);
			}
		}

		int answer = 0;
		for (int i = 0; i < A.size(); i++) {
			int line_sum = 0;
			for (int j = 0; j < A[0].size(); j++) {
				line_sum = line_sum * 2 + A[i][j];
			}
			answer += line_sum;
		}

		return answer;
	}

	void col_reverse(vector<vector<int>>& A, int col_index) {
		for (int i = 0; i < A.size(); i++) {
			A[i][col_index] ^= 1;
		}
	}

	void row_reverse(vector<vector<int>>& A, int row_index) {
		for (int i = 0; i < A[0].size(); i++) {
			A[row_index][i] ^= 1;
		}
	}
};