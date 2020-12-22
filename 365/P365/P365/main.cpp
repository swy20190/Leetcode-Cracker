#include <algorithm>

using namespace std;

class Solution {
public:
	bool canMeasureWater(int x, int y, int z) {
		if (z == 0) {
			return true;
		}
		if (x + y < z) {
			return false;
		}
		return z % gcd(x, y) == 0;
	}
};