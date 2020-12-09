#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	int **endPointMin;
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		int size = A.size();
		if (size == 1) {
			return A[0][0];
		}
		endPointMin = new int*[size];
		for (int i = 0; i < size; i++) {
			endPointMin[i] = new int[size];
		}
		for (int i = 0;i < size; i++) {
			endPointMin[0][i] = A[0][i];
		}
		for (int i = 1; i < size; i++) {
			endPointMin[i][0] = min(endPointMin[i - 1][0], endPointMin[i - 1][1]) + A[i][0];
			endPointMin[i][size - 1] = min(endPointMin[i - 1][size - 1], endPointMin[i - 1][size - 2]) + A[i][size - 1];
			for (int j = 1; j < size-1; j++) {
				endPointMin[i][j] = min(min(endPointMin[i - 1][j - 1], endPointMin[i - 1][j]), endPointMin[i - 1][j + 1]) + A[i][j];
			}
		}
		int answer = INT_MAX;
		for (int i = 0; i < size; i++) {
			if (endPointMin[size - 1][i] < answer) {
				answer = endPointMin[size - 1][i];
			}
		}
		return answer;
	}
};