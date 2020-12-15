#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		if (N < 10) {
			return N;
		}
		string n_str = to_string(N);
		int left_most_nine = n_str.size();
		for (int i = n_str.size() - 2; i >= 0; i--) {
			if (n_str[i] > n_str[i + 1]) {
				n_str[i] --;
				left_most_nine = i + 1;
			}
		}
		for (int i = left_most_nine; i < n_str.size(); i++) {
			n_str[i] = '9';
		}
		return stoi(n_str);
	}
};