#include <algorithm>


using namespace std;

class CustomStack {
	int mSize;
	int *sstack;
	int length;
public:
	CustomStack(int maxSize) {
		mSize = maxSize;
		sstack = new int[mSize];
		length = 0;
	}

	void push(int x) {
		if (length < mSize) {
			sstack[length] = x;
			length++;
		}
	}

	int pop() {
		if (length == 0) {
			return -1;
		}
		else {
			length--;
			return sstack[length];
		}
	}

	void increment(int k, int val) {
		int range = min(k, length);
		for (int i = 0; i < range; i++) {
			sstack[i] += val;
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */