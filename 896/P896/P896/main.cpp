#include <vector>

using namespace std;

class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		bool increase = true;
		bool decrease = true;
		int len = A.size();
		if (len <= 2) {
			return true;
		}
		for (int i = 1; i < len; i++) {
			if (A[i] > A[i - 1]) {
				decrease = false;
			}
			if (A[i] < A[i - 1]) {
				increase = false;
			}
			if ((!increase) && (!decrease)) {
				return false;
			}
		}
		return true;
	}
};