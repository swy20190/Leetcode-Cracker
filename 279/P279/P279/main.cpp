#include <iostream>

using namespace std;


class Solution {
public:
	int numSquares(int n) {
		while (n % 4 == 0) {
			n /= 4;
		}
		if (n % 8 == 7) {
			return 4;
		}

		int sq1 = 0;
		while (sq1*sq1 <= n) {
			int sq2 = sqrt(n - sq1 * sq1);
			if (sq1*sq1 + sq2 * sq2 == n) {
				if (sq1 != 0 && sq2 != 0) {
					return 2;
				}
				else {
					return 1;
				}
			}
			sq1++;
		}
		return 3;
	}
};