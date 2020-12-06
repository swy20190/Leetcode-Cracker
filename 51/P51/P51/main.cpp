#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> one_ans;
		vector<string> one_line = { "Q" };
		one_ans.push_back(one_line);
		if (n == 1) {
			return one_ans;
		}
		int* locations = new int[n];
		for (int i = 0; i < n; i++) {
			locations[i] = -1;
		}
		int currRow = 0;
		vector<vector<string>> answer;
		while (true) {
			if (currRow == 0 && locations[0] == n - 1) {
				break;
			}
			bool findLoc = false;
			for (int i = locations[currRow] + 1; i < n; i++) {
				bool validLoc = true;
				for (int j = 0; j < currRow; j++) {
					if (locations[j] == i || j + locations[j] == currRow + i || j - locations[j] == currRow - i) {
						validLoc = false;
						break;
					}
				}
				if (validLoc) {
					locations[currRow] = i;
					findLoc = true;
					break;
				}
			}
			if (findLoc) {
				if (currRow == n - 1) {
					vector<string> curr_solution;
					for (int i = 0; i < n; i++) {
						string curr_string(n, '.');
						curr_string[locations[i]] = 'Q';
						curr_solution.push_back(curr_string);
					}
					answer.push_back(curr_solution);
					if (locations[currRow] == n - 1) {
						currRow--;
						locations[n - 1] = -1;
					}
				}
				else {
					currRow++;
					locations[currRow] = -1;
				}
			}
			else {
				locations[currRow] = -1;
				currRow--;
			}
		}
		return answer;
	}
};
