#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	vector<vector<int>> largeGroupPositions(string s) {
		vector<vector<int>> answer;
		for (int i = 0, j = 0; j <= s.size(); j++) {
			if (j == s.size() || s[i] != s[j]) {
				int len = j - i;
				if (len >= 3) {
					answer.push_back({ i, j - 1 });
				}
				i = j;
			}
		}
		return answer;
	}
};