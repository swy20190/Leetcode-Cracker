#include <iostream>

using namespace std;


class Solution {
	int** record;
public:
	int uniquePaths(int m, int n) {
		record = new int*[m];
		for (int i = 0; i < m; i++) {
			record[i] = new int[n];
		}
		for (int i = 0; i < n; i++) {
			record[0][i] = 1;
		}
		for (int i = 0; i < m; i++) {
			record[i][0] = 1;
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				record[i][j] = record[i - 1][j] + record[i][j - 1];
			}
		}
		return record[m - 1][n - 1];
	}
};