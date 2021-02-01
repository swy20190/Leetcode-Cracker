#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		string answer = "";
		string curr = "";
		int len = s.size();
		if (len == 0) {
			return answer;
		}
		stack<string> stk;
		for (int i = 0; i < len; i++) {
			if (s[i] != ' ') {
				curr += s[i];
				if (i == len - 1) {
					stk.push(curr);
				}
			}
			else {
				if (curr != "") {
					stk.push(curr);
				}
				curr = "";
			}
		}
		answer += stk.top();
		stk.pop();
		while (!stk.empty()) {
			answer += " ";
			answer += stk.top();
			stk.pop();
		}
		return answer;
	}
};