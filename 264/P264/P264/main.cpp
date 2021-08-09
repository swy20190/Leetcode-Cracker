#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		unordered_set<long> seen;
		priority_queue<long, vector<long>, greater<long>> heap;
		seen.insert(1);
		heap.push(1);
		int ugly = 0;
		vector<int> primes = { 2, 3, 5 };
		for (int i = 0; i < n; i++) {
			long curr = heap.top();
			heap.pop();
			ugly = (int)curr;
			for (int prime : primes) {
				long next = curr * prime;
				if (seen.insert(next).second) {
					heap.push(next);
				}
			}
		}
		return ugly;
	}
};