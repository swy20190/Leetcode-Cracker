#include <queue>
#include <iostream>

using namespace std;


class MedianFinder {

	priority_queue<int, vector<int>, less<int>> smaller_half;
	priority_queue<int, vector<int>, greater<int>> larger_half;
	int size = 0;
	
public:
	/** initialize your data structure here. */
	MedianFinder() {
		size = 0;
	}

	void addNum(int num) {
		size++;
		if (smaller_half.empty()) {
			smaller_half.push(num);
			return;
		}
		if (smaller_half.top() > num) {
			smaller_half.push(num);
		}
		else {
			larger_half.push(num);
		}
		if (smaller_half.size() == larger_half.size() + 2) {
			int tmp = smaller_half.top();
			smaller_half.pop();
			larger_half.push(tmp);
		}
		if (smaller_half.size() + 2 == larger_half.size()) {
			int tmp = larger_half.top();
			larger_half.pop();
			smaller_half.push(tmp);
		}
	}

	double findMedian() {
		if (smaller_half.size() > larger_half.size()) {
			return smaller_half.top();
		}
		else if (smaller_half.size() < larger_half.size()) {
			return larger_half.top();
		}
		else {
			return (smaller_half.top() + larger_half.top()) / 2.0;
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
	MedianFinder test;
	test.addNum(1);
	test.addNum(2);
	cout << test.findMedian();
}