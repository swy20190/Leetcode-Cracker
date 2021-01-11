#include <iostream>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x == 0) {
			return 0;
		}
		if (x <= 3) {
			return 1;
		}
		if (x == 4) {
			return 2;
		}
		int min = 0;
		int max = x;
		while (max - min > 1) {
			int mid = (max + min) / 2;
			if (x / mid < mid) {
				max = mid;
			}
			else {
				min = mid;
			}
		}
		return min;
	}
};