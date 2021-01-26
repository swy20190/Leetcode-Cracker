#include <iostream>

using namespace std;

class Solution {
public:
	int smallestRepunitDivByK(int K) {
		if (K % 2 == 0 || K % 5 == 0) {
			return -1;
		}
		int digit = 1;
		for (int i = 1; i%K != 0; digit++) {
			i = i % K;
			i = i * 10 + 1;
		}
		return digit;
	}
};