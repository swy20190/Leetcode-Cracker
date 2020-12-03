#include <iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n >= 0) {
			return qPow(x, (long)n);
		}
		else if (x == 1||x==0) {
			return x;
		}
		else {
			return 1.0 / qPow(x, abs((long)n));
		}
	}

	double qPow(double x, long n) {
		if (n == 0) {
			return 1;
		}
		if (n == 1) {
			return x;
		}
		if (n % 2 == 0) {
			double tmpPow = myPow(x, n / 2);
			return tmpPow * tmpPow;
		}
		else {
			double tmpPow = myPow(x, n / 2);
			return tmpPow * tmpPow*x;
		}
	}
};