#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
	string convert(string s, int numRows) {
		vector<string> rows(numRows);
		string answer;
		if (numRows == 1) {
			return s;
		}
		int len = s.length();
		for (int i = 0; i < len; i++) {
			int mod = i % (2 * numRows - 2);
			if (mod < numRows) {
				rows[mod].append(string(1, s[i]));
			}
			else {
				rows[2 * numRows - 2 - mod].append(string(1, s[i]));
			}
		}
		for (int i = 0; i < numRows; i++) {
			answer.append(rows[i]);
		}
		return answer;
	}
};

int main() {
	Solution solution;
	cout << solution.convert("LEETCODEISHIRING", 4);
}