#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int m = nums.size();
		if (m == 0) {
			return nums;
		}
		int n = nums[0].size();
		if (n == 0) {
			return nums;
		}
		if (m*n != r * c) {
			return nums;
		}
		vector<vector<int>> answer(r, vector<int>(c));
		for (int i = 0; i < m*n; i++) {
			answer[i / c][i%c] = nums[i / n][i%n];
		}
		return answer;
	}
};