#include <string>

using namespace std;

class Solution {
public:
	int scoreOfParentheses(string S) {
		int len = S.size();
		int answer = 0;
		int ptr = 0;
		for (int i = 0; i < len; i++) {
			if (S[i] == '(') {
				if (ptr == 0) {
					ptr = 1;
				}
				else {
					ptr = ptr << 1;
				}
			}
			else if (S[i] == ')') {
				if (S[i - 1] == '(') {
					answer += ptr;
				}
				ptr = ptr >> 1;
			}
		}
		return answer;
	}
};