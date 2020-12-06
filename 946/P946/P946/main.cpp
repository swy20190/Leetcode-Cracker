#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> simulator;
		int push_len = pushed.size();
		int popped_len = popped.size();
		if (push_len != popped_len) {
			return false;
		}
		int curr_push = 0;
		int curr_pop = 0;
		while (curr_push < push_len) {
			if (simulator.empty() || simulator.top() != popped[curr_pop]) {
				simulator.push(pushed[curr_push]);
				curr_push++;
			}
			else {
				simulator.pop();
				curr_pop++;
			}
		}
		while (curr_pop < popped_len) {
			if (simulator.top() != popped[curr_pop] || simulator.empty()) {
				return false;
			}
			else {
				simulator.pop();
				curr_pop++;
			}
		}
		return simulator.empty();
	}
};