#include <iostream>

using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		uint32_t tmp = x ^ y;
		tmp = (tmp & 0x55555555) + ((tmp >> 1) & 0x55555555);
		tmp = (tmp & 0x33333333) + ((tmp >> 2) & 0x33333333);
		tmp = (tmp & 0x0f0f0f0f) + ((tmp >> 4) & 0x0f0f0f0f);
		tmp = (tmp & 0x00ff00ff) + ((tmp >> 8) & 0x00ff00ff);
		tmp = (tmp & 0x0000ffff) + ((tmp >> 16) & 0x0000ffff);
		return (int)tmp;
	}
};