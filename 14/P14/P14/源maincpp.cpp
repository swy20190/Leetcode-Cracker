#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string answer = "";
		if (strs.empty()) {
			return "";
		}
		int range = strs.size();
		int ptr = 0;
		int minLen = INT_MAX;
		for (int i = 0; i < range; i++) {
			int tmpLen = strs[i].length();
			if (tmpLen < minLen) {
				minLen = tmpLen;
			}
		}
		while (ptr < minLen) {
			bool allCommon = true;
			char current = strs[0][ptr];
			for (int i = 0; i < range; i++) {
				if (strs[i][ptr] != current) {
					allCommon = false;
					break;
				}
			}
			if (allCommon) {
				answer.append(1, strs[0][ptr]);
				ptr++;
			}
			else {
				break;
			}
		}

		return answer;
	}
};

int main() {
	Solution solution;
	vector<string> strs;
	strs.push_back("yamato");
	strs.push_back("yamamoto");
	strs.push_back("yamakaze");
	cout << solution.longestCommonPrefix(strs);
}