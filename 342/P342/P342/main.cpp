#include <iostream>

using namespace std;

class Solution {
public:
	bool isPowerOfFour(int n) {
		return (n == 0x00000001) ||
			(n == 0x00000004) ||
			(n == 0x00000010) ||
			(n == 0x00000040) ||
			(n == 0x00000100) ||
			(n == 0x00000400) ||
			(n == 0x00001000) ||
			(n == 0x00004000) ||
			(n == 0x00010000) ||
			(n == 0x00040000) ||
			(n == 0x00100000) ||
			(n == 0x00400000) ||
			(n == 0x01000000) ||
			(n == 0x04000000) ||
			(n == 0x10000000) ||
			(n == 0x40000000);
	}
};