#include <queue>

using namespace std;

class MyStack {
	queue<int> q1;
	queue<int> q2;
	int _top;
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		_top = x;
		if (q1.empty()) {
			q2.push(x);
		}
		else {
			q1.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (q1.empty()) {
			while (q2.size() > 2) {
				q1.push(q2.front());
				q2.pop();
			}
			if (q2.size() == 2) {
				_top = q2.front();
				q1.push(_top);
				q2.pop();
			}
			int ret = q2.front();
			q2.pop();
			return ret;
		}
		else {
			while (q1.size() > 2) {
				q2.push(q1.front());
				q1.pop();
			}
			if (q1.size() == 2) {
				_top = q1.front();
				q2.push(_top);
				q1.pop();
			}
			int ret = q1.front();
			q1.pop();
			return ret;
		}
	}

	/** Get the top element. */
	int top() {
		return _top;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
};