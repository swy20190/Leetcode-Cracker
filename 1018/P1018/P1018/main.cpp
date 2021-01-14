#include <vector>

using namespace std;

class Solution {
public:
	vector<bool> prefixesDivBy5(vector<int>& A) {
		vector<bool> answer(A.size());
		int tmp = 0;
		for (int i = 0; i < A.size(); i++) {
			tmp = (tmp * 2 + A[i]) % 10;
			if (tmp == 0 || tmp == 5) {
				answer[i] = true;
			}
			else {
				answer[i] = false;
			}
		}
		return answer;
	}
};