#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row_num = triangle.size();
		if (row_num == 1) {
			return triangle[0][0];
		}
		for (int i = 1; i < row_num; i++) {
			triangle[i][0] += triangle[i - 1][0];
			triangle[i][i] += triangle[i - 1][i - 1];
			for (int j = 1; j <= i - 1; j++) {
				triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
			}
		}
		int answer = INT_MAX;
		for (auto sum : triangle[row_num - 1]) {
			if (sum < answer) {
				answer = sum;
			}
		}
		return answer;
	}
};