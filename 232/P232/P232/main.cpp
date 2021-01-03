#include <stack>

using namespace std;

class MyQueue {
	stack<int> s1;
	stack<int> s2;
	
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s1.push(x);
		
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (!s2.empty()) {
			int ret = s2.top();
			s2.pop();
			
			return ret;
		}
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			int ret = s2.top();
			s2.pop();
			
			return ret;
		}
	}

	/** Get the front element. */
	int peek() {
		if (!s2.empty()) {
			return s2.top();
		}
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			return s2.top();
		}
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s1.empty() && s2.empty();
	}
};