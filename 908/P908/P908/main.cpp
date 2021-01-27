#include <vector>

using namespace std;

class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int minA = 114514;
		int maxA = -1;
		for (auto a : A) {
			if (a < minA) {
				minA = a;
			}
			if (a > maxA) {
				maxA = a;
			}
		}
		int answer = maxA - minA > 2 * K ? maxA - minA - 2 * K : 0;
		return answer;
	}
};