#include <iostream>

using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		int* locations = new int[n];
		for (int i = 0; i < n; i++) {
			locations[i] = -1;
		}
		int currRow = 0;
		int answer = 0;
		while (true) {
			if (currRow == 0 && locations[0] == n - 1) {
				break;
			}
			bool findLoc = false;
			for (int i = locations[currRow]+1; i < n; i++) {
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
					answer++;
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

int main() {
	Solution solution;
	cout << solution.totalNQueens(1);
}