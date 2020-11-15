#include <string>
#include <stack>
#include <iostream>


using namespace std;



class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0) {
			return true;
		}
		stack<char> check_stack;
		bool answer = true;
		int len = s.length();
		for (int i = 0; i < len; i++) {
			char tmp = s[i];
			if (tmp == '(' || tmp == '[' || tmp == '{') {
				check_stack.push(tmp);
			}
			else {
				if (check_stack.empty()) {
					answer = false;
					break;
				}
				else if (tmp == ')') {
					if (check_stack.top() == '(') {
						check_stack.pop();
					}
					else {
						answer = false;
						break;
					}
				}
				else if (tmp == ']') {
					if (check_stack.top() == '[') {
						check_stack.pop();
					}
					else {
						answer = false;
						break;
					}
				}
				else  {
					if (check_stack.top() == '{') {
						check_stack.pop();
					}
					else {
						answer = false;
						break;
					}
				}
			}
		}
		if (!check_stack.empty()) {
			answer = false;
		}
		return answer;
	}
};


int main() {
	Solution solution;
	cout << solution.isValid("([)]");
}