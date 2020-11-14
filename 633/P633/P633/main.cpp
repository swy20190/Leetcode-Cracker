#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
	bool judgeSquareSum(int c) {
		long l_c = (long)c;
		long head = 0;
		long tail = (long)sqrt(c);
		bool answer = false;
		while (head <= tail) {
			long tmp_sum = (long)(head * head + tail * tail);
			if (tmp_sum == l_c) {
				answer = true;
				break;
			}
			else if (tmp_sum < l_c) {
				head++;
			}
			else {
				tail--;
			}
		}
		return answer;
	}
};

int main() {
	Solution solution;
	cout << solution.judgeSquareSum(114514);
}