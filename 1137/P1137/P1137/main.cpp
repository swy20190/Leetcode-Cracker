#include <iostream>

using namespace std;

class Solution {
public:
	int tribonacci(int n) {
		int tribs[38] = { 0 };
		if (n == 0) {
			return 0;
		}
		if (n == 1 || n == 2) {
			return 1;
		}
		tribs[0] = 0;
		tribs[1] = 1;
		tribs[2] = 1;
		for (int i = 4; i <= n; i++) {
			tribs[i] = tribs[i - 1] + tribs[i - 2] + tribs[i - 3];
		}
		return tribs[n];
	}
};