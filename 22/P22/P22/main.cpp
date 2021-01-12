#include <vector>
#include <string>

using namespace std;


class Solution {
	vector<string> answer;
public:
	vector<string> generateParenthesis(int n) {
		dfs("", 0, 0, n);
		return answer;
	}

	void dfs(string tmp, int l, int r, int n) {
		if (l == n && r == n) {
			answer.push_back(tmp);
		}

		if (r > l || l > n) {
			return;
		}
		dfs(tmp + "(", l + 1, r, n);
		dfs(tmp + ")", l, r + 1, n);
	}
};