#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minFlipsMonoIncr(string S) {
		int total0 = 0;
		int total1 = 0;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '0') {
				total0++;
			}
			if (S[i] == '1') {
				total1++;
			}
		}
		int answer = total0;
		int front0 = 0;
		int front1 = 0;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '0') {
				front0++;
			}
			if (S[i] == '1') {
				front1++;
			}
			int times = front1 + total0 - front0;
			answer = min(answer, times);
		}
		return answer;
	}
};