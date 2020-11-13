#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int len = s.size();
		if (len == 0) {
			return;
		}
		int head = 0;
		int tail = len-1;
		while (head < tail) {
			char tmp = s[head];
			s[head] = s[tail];
			s[tail] = tmp;
			head++;
			tail--;
		}
	}
};


int main() {
	vector<char> test;
	test.push_back('y');
	test.push_back('a');
	test.push_back('m');
	test.push_back('a');
	test.push_back('t');
	test.push_back('o');
	Solution solution;
	solution.reverseString(test);
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << " ";
	}
}