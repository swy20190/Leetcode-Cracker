#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		if (n < 10) {
			return n;
		}
		int digitCnt = 0;
		long long bigger_size = pow(10, digitCnt)*(digitCnt + 1) * 9;
		while (n > bigger_size) {
			n -= bigger_size;
			digitCnt++;
			bigger_size = pow(10, digitCnt)*(digitCnt + 1) * 9;
		}
		long long curr_num = pow(10, digitCnt) + (n - 1) / (digitCnt + 1);
		return to_string(curr_num).at(n - 1 - (n - 1) / (digitCnt + 1)*(digitCnt + 1)) - '0';
	}
};