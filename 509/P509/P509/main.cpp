#include <iostream>

using namespace std;

class Solution {
public:
	int fib(int N) {
		int* fibs = new int[32];
		fibs[0] = 0;
		fibs[1] = 1;
		for (int i = 2; i <= N; i++) {
			fibs[i] = fibs[i - 1] + fibs[i - 2];
		}
		return fibs[N];
	}
};