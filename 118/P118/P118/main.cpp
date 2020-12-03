#include <vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> answer;
		for (int i = 0; i < numRows; i++) {
			answer.push_back(vector<int>(i + 1));
		}
		if (numRows == 0) {
			return answer;
		}
		if (numRows >= 1) {
			answer[0] = vector<int>{ 1 };
		}
		if (numRows >= 2) {
			answer[1] = vector<int>{ 1, 1 };
		}
		for (int i = 2; i < numRows; i++) {
			answer[i][0] = 1;
			for (int j = 1; j < i; j++) {
				answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
			}
			answer[i][i] = 1;
		}
		return answer;
	}
};