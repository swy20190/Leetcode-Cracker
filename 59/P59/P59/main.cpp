#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> answer(n, vector<int>(n, 0));
		int current_value = 1;
		int round_num = n / 2;
		for (int i = 0; i < round_num; i++) {
			for (int j = i; j < n - i - 1; j++) {
				answer[i][j] = current_value;
				current_value++;
			}
			for (int j = i; j < n - i - 1; j++) {
				answer[j][n - i - 1] = current_value;
				current_value++;
			}
			for (int j = n - i - 1; j > i; j--) {
				answer[n - i - 1][j] = current_value;
				current_value++;
			}
			for (int j = n - i - 1; j > i; j--) {
				answer[j][i] = current_value;
				current_value++;
			}
		}
		if (current_value == n * n) {
			answer[n / 2][n / 2] = n * n;
		}
		return answer;
	}
};