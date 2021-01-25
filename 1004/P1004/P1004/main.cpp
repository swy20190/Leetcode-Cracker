#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int zero_cnt = 0;
		int left = 0;
		int right = -1;
		int answer = 0;
		int len = A.size();
		if (len == 0) {
			return 0;
		}
		while (right < len - 1) {
			right++;
			if (A[right] == 0) {
				zero_cnt++;
			}
			if (zero_cnt > K) {
				while (left <= right) {
					if (A[left] == 1) {
						left++;
					}
					else {
						left++;
						zero_cnt--;
						break;
					}
				}
			}
			answer = max(answer, right - left + 1);
		}
		return answer;
	}
};