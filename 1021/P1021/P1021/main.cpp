#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	string removeOuterParentheses(string S) {
		string answer = "";
		stack<char> s;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == ')') {
				s.pop();
			}
			if (!s.empty()) {
				answer += S[i];
			}
			if (S[i] == '(') {
				s.push('(');
			}
		}
		return answer;
	}
};