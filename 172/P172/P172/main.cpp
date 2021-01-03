#include <iostream>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int cnt_5 = 0;
		while (n >= 5) {
			cnt_5 += n / 5;
			n /= 5;
		}
		return cnt_5;
	}
};