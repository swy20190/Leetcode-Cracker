#include <iostream>

using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num == 1) {
			return true;
		}
		long x = num;
		while (x*x > num) {
			x = (x + num / x) / 2;
			if (x*x == num) {
				return true;
			}
		}
		return false;
	}
};