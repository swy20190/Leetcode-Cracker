#include <iostream>

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		if (b == 0) {
			return a;
		}
		unsigned next = a&b;
		next <<= 1;
		return getSum(a^b, next);
	}
};