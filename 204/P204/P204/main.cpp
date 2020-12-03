#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		int cnt = 0;
		vector<bool> isPrime(n, true);
		if (n > 2) {
			cnt++;
		}
		if (n > 3) {
			cnt++;
		}

		for (int i = 3; i < n; i++) {
			if (!(i % 2) || !(i % 3)) {
				continue;
			}
			if (isPrime[i]) {
				for (long j = i; i*j < n; j++) {
					isPrime[j*i] = false;
				}
				cnt++;
			}
		}
		return cnt;
	}
};