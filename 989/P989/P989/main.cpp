#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		if (K == 0) {
			return A;
		}
		string kstr = to_string(K);
		int len = max(A.size(), kstr.size());
		vector<int> answer(len + 1, 0);

		int remain = 0;
		for (int i = A.size() - 1; i >= 0; i--) {
			int num = A[i];
			K += num;
			remain = K % 10;
			answer[len--] = remain;
			K /= 10;
		}

		if (K) {
			while (K > 9) {
				remain = K % 10;
				answer[len--] = remain;
				K /= 10;
			}
			answer[len--] = K;
		}

		if (!answer[0]) {
			answer.erase(answer.begin());
		}

		return answer;
	}
};