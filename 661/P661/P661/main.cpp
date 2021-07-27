#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> num = M;
		int row = M.size();
		int col = M[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int m = 1;
				int n;
				if (M[i][j] != 0) {
					n = M[i][j];
				}
				else {
					n = 0;
				}
				if (i > 0) {
					m++;
					n += M[i - 1][j];
				}
				if (i < row - 1) {
					m++;
					n += M[i + 1][j];
				}
				if (j > 0) {
					m += 1;
					n += M[i][j - 1];
				}
				if (j < col - 1) {
					m += 1;
					n += M[i][j + 1];
				}
				if (i > 0 && j > 0) {
					m += 1;
					n += M[i - 1][j - 1];
				}
				if (i > 0 && j < col - 1) {
					m += 1;
					n += M[i - 1][j + 1];
				}
				if (i < row - 1 && j>0) {
					m += 1;
					n += M[i + 1][j - 1];
				}
				if (i < row - 1 && j < col - 1) {
					m += 1;
					n += M[i + 1][j + 1];
				}
				num[i][j] = n / m;
			}
		}
		return num;
	}
};