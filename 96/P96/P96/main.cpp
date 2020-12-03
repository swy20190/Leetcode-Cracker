#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		vector<int> store(n+1, -1);
		return dp(n, store);
	}

	int dp(int n, vector<int>& store) {
		if (store[n] != -1) {
			return store[n];
		}
		if (n == 1||n == 0) {
			return 1;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += dp(i, store)*dp(n-1-i, store);
		}
		store[n] = sum;
		return sum;
	}
};