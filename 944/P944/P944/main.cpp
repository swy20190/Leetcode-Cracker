#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		if (A.empty()) {
			return 0;
		}
		int cnt = 0;
		int rows = A.size();
		int cols = A[0].size();

		for (int j = 0; j < cols; j++) {
			for (int i = 0; i < rows - 1; i++) {
				if (A[i][j] > A[i + 1][j]) {
					cnt++;
					break;
				}
			}
		}
		return cnt;
	}
};