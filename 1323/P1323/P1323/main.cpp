#include <stack>

using namespace std;

class Solution {
public:
	int maximum69Number(int num) {
		stack<int> stack_69;
		while (num != 0) {
			stack_69.push(num % 10);
			num /= 10;
		}
		int answer = 0;
		bool changed = false;
		while (!stack_69.empty()) {
			int tmp = stack_69.top();
			if (tmp == 6 && !changed) {
				tmp = 9;
				changed = true;
			}
			answer = answer * 10 + tmp;
			stack_69.pop();
		}
		return answer;
	}
};