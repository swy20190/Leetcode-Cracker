#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		int len = A.size();
		if (len < 3) {
			return 0;
		}
		sort(A.begin(), A.end(),greater<int>());
		for (int i = 0; i < len - 2; i++) {
			if (A[i + 1] + A[i + 2] > A[i]) {
				return A[i] + A[i + 1] + A[i + 2];
			}
		}
		return 0;
	}
};